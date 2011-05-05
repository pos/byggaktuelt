<?php
// $Id: twitter-pull-listing.tpl.php,v 1.1.2.2 2010/04/02 17:01:56 detour Exp $

/**
 * @file
 * Theme template for a list of tweets.
 *
 * Available variables in the theme include:
 *
 * 1) An array of $tweets, where each tweet object has:
 *   $tweet->id
 *   $tweet->username
 *   $tweet->userphoto
 *   $tweet->text
 *   $tweet->timestamp
 *
 * 2) $twitkey string containing initial keyword.
 *
 * 3) $title
 *
 */
?>
<div class="tweets-pulled-listing">

  <?php if (!empty($title)): ?>
    <h2><?php print $title; ?></h2>
  <?php endif; ?>

  <?php if (is_array($tweets)): ?>
    <ul class="tweets-pulled-listing">
    <?php foreach ($tweets as $tweet): ?>
      <li>
        <div class="tweet-authorphoto"><img src="<?php print $tweet->userphoto; ?>"></div>
        <span class="tweet-author"><?php print l($tweet->username, 'http://twitter.com/' . $tweet->username); ?></span>
        <span class="tweet-text"><?php print twitter_pull_add_links($tweet->text); ?></span>
        <div class="tweet-time"><?php print l(format_interval(time() - $tweet->timestamp) . ' ' . t('ago'), 'http://twitter.com/' . $tweet->username . '/status/' . $tweet->id);?></div>
        <div class="tweet-divider"></div>
      </li>
    <?php endforeach; ?>
    </ul>
  <?php endif; ?>
</div>
