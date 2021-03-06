<?php 
// $Id: l10n_update.check.inc,v 1.3.2.1 2010/08/17 13:21:40 jareyero Exp $
/**
 * @file
 * Reusable API for l10n remote updates using $source objects
 * 
 * These functions may not be safe for the installer as they use variables and report using watchdog
 *   
 * All these functions will use $source objects which may have these properties:
 * - project, Project name
 * - language, Language code
 * - type, Source type: 'download' or 'localfile'
 * - filepath, Local file path
 * - fileurl, Remote file URL for downloads
 * - keep, TRUE to keep the downloaded file
 * - timestamp, Last update time of the file
 */

require_once 'l10n_update.inc';

/**
 * Fetch update information for all projects / all languages
 * 
 * We refresh anyway if the data is older than a day
 * 
 * @return array()
 *   Available releases indexed by project and language
 */
function l10n_update_available_releases($refresh = FALSE) {  
  $frequency = variable_get('l10n_update_check_frequency', 0) * 24 * 3600; 
  if (!$refresh && ($cache = cache_get('l10n_update_available_releases')) && (!$frequency || $cache->created > time() - $frequency)) {
    return $cache->data;
  }
  else {
    $projects = l10n_update_get_projects(TRUE);
    $languages = l10n_update_language_list();
    $local = variable_get('l10n_update_check_mode', L10N_UPDATE_CHECK_ALL) & L10N_UPDATE_CHECK_LOCAL;
    $remote = variable_get('l10n_update_check_mode', L10N_UPDATE_CHECK_ALL) & L10N_UPDATE_CHECK_REMOTE;
    $available = l10n_update_check_projects($projects, array_keys($languages), $local, $remote);
    cache_set('l10n_update_available_releases', $available, 'cache', $frequency ? time() + $frequency : CACHE_PERMANENT);
    return $available;
  }
}

/**
 * Check latest release for project, languages
 * 
 * @param $projects
 *   Projects to check (objects)
 * @param $languages
 *   Array of language codes to check, none to check all
 * @return array
 *   Available sources indexed by project, language
 */
function l10n_update_check_projects($projects, $languages = NULL, $check_local = TRUE, $check_remote = TRUE) {
  $languages = $languages ? $languages : array_keys(l10n_update_language_list());
  $result = array();
  foreach ($projects as $name => $project) {
    foreach ($languages as $lang) {
      $source = l10n_update_source_build($project, $lang);
      if ($update = l10n_update_source_check($source, $check_local, $check_remote)) {
        $result[$name][$lang] = $update;
      }
    }
  }
  return $result;
}

/**
 * Compare available releases with history and get list of downloadable updates
 */
function l10n_update_build_updates($history, $available) {
   $updates = array();
   foreach ($available as $name => $project_updates) {    
     foreach ($project_updates as $lang => $update) {
       if (!empty($update->timestamp)) {
         $current = !empty($history[$name][$lang]) ? $history[$name][$lang] : NULL;
         // Add when not current, timestamp newer or version difers (newer version)
         if (_l10n_update_source_compare($current, $update) > 1 || $current->version != $update->version) {
           $updates[$name][$lang] = $update;
         }
       }
     }
   }
   return $updates;
}

/**
 * Check updates for active projects and languages
 */
function l10n_update_check_translations($count, $before, $limit = 1) {
  $projects = l10n_update_get_projects();
  $updated = $checked = array();
  // Select active projects x languages ordered by last checked time
  $sql = "SELECT p.name, l.language AS lang, f.* FROM {l10n_update_project} p INNER JOIN {languages} l";
  $sql .= " LEFT JOIN {l10n_update_file} f ON p.name = f.project AND l.language = f.language";
  $sql .= " WHERE p.status = 1 AND l.enabled = 1 AND (f.status IS NULL OR f.status = 1 AND f.last_checked < %d) ORDER BY last_checked";
  $result = db_query_range($sql, $before, 0, $count);
  if ($result) {
    $local = variable_get('l10n_update_check_mode', L10N_UPDATE_CHECK_ALL) & L10N_UPDATE_CHECK_LOCAL;
    $remote = variable_get('l10n_update_check_mode', L10N_UPDATE_CHECK_ALL) & L10N_UPDATE_CHECK_REMOTE;
    while (($check = db_fetch_object($result)) && (count($files) <= $limit)) {
      $checked[] = $check;
      if (!empty($projects[$check->name])) {
        $project = $projects[$check->name];
        $update = NULL;
        $source = l10n_update_source_build($project, $check->lang);
        if ($available = l10n_update_source_check($source, $local, $remote)) {
          $current = $check->filename ? $check : NULL;
          if (!$current || _l10n_update_source_compare($current, $available) > 1 || $current->version != $available->version) {
            $update = $available;
          } 
        }
        if ($update) {
          // The update functions will update data and timestamps too
          l10n_update_source_update($update, variable_get('l10n_update_import_mode', LOCALE_IMPORT_KEEP));
          $updated[] = $update;
        }
        elseif ($current) {
          // No update available, just update timestamp for this row
          db_query("UPDATE {l10n_update_file} SET last_checked = %d WHERE project = '%s' AND language = '%s'", time(), $current->project, $current->language);
        }
        elseif ($source) {
          // Create a new record just for keeping last checked time
          $source->last_checked = time();
          drupal_write_record('l10n_update_file', $source);
        }
      }
    } 
  }
  return array($checked, $updated);
}

/**
 * Build abstract translation source, to be mapped to a file or a download
 */
function l10n_update_source_build($project, $langcode, $filename = L10N_UPDATE_DEFAULT_FILENAME) {
  $source = clone $project;
  $source->project = $project->name;
  $source->language = $langcode;
  $source->filename = l10n_update_build_string($source, $filename);
  return $source;
}

/**
 * Check local and remote sources for the file
 */
function l10n_update_source_check($source, $check_local = TRUE, $check_remote = TRUE) {
  $local = $remote = NULL;
  if ($check_local) {
    $check = clone $source;
    if (l10n_update_source_check_file($check)) {
      $local = $check;
    }
  }
  if ($check_remote) {
    $check = clone $source;
    if (l10n_update_source_check_download($check)) {
      $remote = $check;
    }
  }
  // Get remote if newer than local only, they both can be empty
  return _l10n_update_source_compare($local, $remote) < 0 ? $remote : $local;
}

/**
 * Check download
 */
function l10n_update_source_check_download($source) {
  $url = l10n_update_build_string($source, $source->l10n_path);
  $result = l10n_update_http_check($url);
  if ($result && !empty($result->updated)) {
    $source->type = 'download';
    // There may have been redirects so we store the resulting url
    $source->fileurl = $result->url;
    $source->timestamp = $result->updated;
    return $result;
  } 
}

/**
 * Check whether we've got the file in the filesystem under 'translations'
 * 
 * It will search, similar to modules and themes:
 * - translations
 * - sites/all/translations
 * - sites/mysite/translations
 * 
 * Using name as the key will return just the last one found
 * 
 * @return Object
 *  File object if found (filename, basename, name)
 */
function l10n_update_source_check_file($source, $directory = 'translations') {
  $filename = preg_quote($source->filename) . '$';
  // Using the 'name' key will return 
  if ($files = drupal_system_listing($filename, $directory, 'name', 0)) {
    $file = current($files);
    $source->type = 'localfile';
    $source->filepath = $file->filename;
    $source->timestamp = filemtime($file->filename);
    return $file;
  }
}

/**
 * Download and import or just import source, depending on type
 * 
 * @param $source
 *   Information about the location of the translation
 */
function l10n_update_source_update($source, $mode) {
  if ($source->type == 'localfile' || l10n_update_source_download($source)) {
    if (l10n_update_source_import($source, $mode)) {
      l10n_update_source_history($source);
      return TRUE;
    }
  }
}

/**
 * Import source into locales table
 */
function l10n_update_source_import($source, $mode) {
  if (!empty($source->filepath) && l10n_update_import_file($source->filepath, $source->language, $mode)) {
    $source->last_updated = time();
    $source->import_date = time();
    return TRUE;
  }
}
      
/**
 * Download source file from remote server
 * 
 * If succesful this function returns the downloaded file in two ways:
 * - As a temporary $file object
 * - As a file path on the $source->filepath property.
 * 
 * @param $source
 *   Source object with all parameters
 *   - fileurl, url to download
 *   - filepath, alternate destination. If not present a temporary file will be used and the path returned here
 * @return object
 *   $file object if download successful
 */
function l10n_update_source_download($source) {
  if (!empty($source->filepath)) {
    $destination = $source->filepath;
  }
  elseif ($directory = variable_get('l10n_update_download_store', '')) {
    $destination = $directory . '/' . $source->filename;
  }
  else {
    $destination = NULL;
  }
  if ($file = l10n_update_download_file($source->fileurl, $destination)) {
    $source->filepath = $file;
    return $file;
  }
}

/**
 * Update the file history table and delete the file if temporary
 * 
 * @param $file
 *   Object representing the file just imported or downloaded
 */
function l10n_update_source_history($file) {
  // Update history table
  l10n_update_file_history($file);
  // If it's a downloaded file and not marked for keeping, delete file
  if ($file->type == 'download' && empty($file->keep)) {
    file_delete($file->filepath);
    $file->filepath = '';
  }
  return $status;
}

/**
 * Compare two update sources, looking for the newer one (bigger timestamp)
 * 
 * This function can be used as a compare callback. It returns an integer less than, equal to, or greater than zero
 * if the first argument is considered to be respectively less than, equal to, or greater than the second
 * 
 * @return integer
 *   
 */
function _l10n_update_source_compare($current, $update) {
  if ($current && $update) {
    if ($current->timestamp == $update->timestamp) {
      return 0;
    }
    else {
      return $current->timestamp > $update->timestamp ? 1 : -1;
    }    
  }
  elseif ($current && !$update) {
    return 1;
  }
  elseif (!$current && $update) {
    return -1;
  }
  else {
    return 0;
  }
}

/**
 * Prepare update list
 * 
 * @param $updates
 *   Update sources array that may be indexed in multiple ways
 * @param $projects
 *   Array of project names to be included, others will be filtered out
 * @param $languages
 *   Array of language codes to be included, others will be filtered out
 *
 * @return
 *   Plain array of filtered updates with directory applied
 */
function _l10n_update_prepare_updates($updates, $projects = NULL, $languages = NULL) {
  $result = array();
  foreach ($updates as $key => $update) {
    if (is_array($update)) {
      // It is a sub array of updates yet, process and merge
      $result = array_merge($result, _l10n_update_prepare_updates($update, $projects, $languages));
    }
    elseif ((!$projects || in_array($update->project, $projects)) && (!$languages || in_array($update->language, $languages))) {
      if ($directory && empty($update->filepath)) {
        // If we have a destination folder set just if we have no filepath
        if (empty($update->filepath)) {
          $update->filepath = $directory . '/' . $update->filename;
          $update->keep = TRUE;
        }
      }
      $result[] = $update;
    }
  }
  return $result;
}