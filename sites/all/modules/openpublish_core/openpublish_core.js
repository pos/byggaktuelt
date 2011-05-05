// #modalframe-element div#admin-toolbar {display: none;}

Drupal.behaviors.openpublish_core = function(context) {    

  //-- Deprecate this function since the same functionality is now supported by modalframe module	
  return;

  /** Fix Admin module breaking modalframe module **/

  if ($(".modalframe-page-wrapper").length > 0) {
     $(document.body).removeClass('admin-expanded');
     $(document.body).removeClass('admin-nw');
     $(document.body).removeClass('admin-vertical');
     $('#admin-toolbar').css('display', 'none');
  }
}
