<?php
// $Id: twitter_pull.class.inc,v 1.1.2.3 2010/04/02 17:01:56 detour Exp $

/**
 * @file
 * twitter pull class implementation
 */

class twitter_puller {

  var $twitkey;
  var $num_items;
  var $tweets;

  /**
  * @param $twitkey
  *     Twitter key, which can be a username (prepended with @) or hashtag (prepended with #)
  * @param $num_items
  *     maximum number of tweets to pull from Twitter.
  */
  function __construct($twitkey, $num_items) {

    $this->twitkey = $twitkey;
    $this->num_items = $num_items;

    $this->check_arguments();

  }

  function check_arguments() {

    if (empty($this->twitkey) || drupal_strlen($this->twitkey) < 2) {
      throw new Exception(t('Twitter key may not be empty.'));
    }

    $num = intval($this->num_items);
    if ($num <= 0 || $num > 200) {
      throw new Exception(t('Number of Twitter items to pull must be a positive integer less than or equal to 200.'));
    }

  }

  function get_items() {

    $prefix = drupal_substr($this->twitkey, 0, 1);
    $slash = strpos($this->twitkey, '/', 1);
    $num = intval($this->num_items);

    // lists have the format @username/listname
    if ($prefix == '@' && $slash !== FALSE) {
      $username = drupal_substr($this->twitkey, 1, $slash - 1);
      $listname = drupal_substr($this->twitkey, $slash + 1);
      $url = 'http://api.twitter.com/1/'. urlencode($username) .'/lists/'. urlencode($listname) .'/statuses.json?per_page='. $num;
    }
    // if the first character is @, then consider the key a username
    elseif ($prefix == "@") {
      $key = drupal_substr($this->twitkey, 1);
      $url = 'http://twitter.com/statuses/user_timeline.json?screen_name='. urlencode($key) .'&count='. $num;
    }
    // otherwise, use the key as a search term
    else {
      if ($num > 100) {
        $num = 100;
      }
      $url = 'http://search.twitter.com/search.json?q='. urlencode($this->twitkey) .'&rpp='. $num;
    }

    $ret = drupal_http_request($url);

    if ($ret->code < 200 || $ret->code > 399) {
      $errmsg = json_decode($ret->data);
      $errmsg = t('The error message received was: @message.', array('@message' => $errmsg->error));
      if ($ret->code == 400) {
        $errmsg .= t('This site may be subject to rate limiting. For more information, see:') . 'http://apiwiki.twitter.com/Rate-limiting';
      }
      throw new Exception(t('Could not retrieve data from Twitter.') .' '. $errmsg);
    }

    $items = json_decode($ret->data);
    $this->parse_items($items);

  }

  function parse_items($items) {
    $tweets = array();

    //-- If search response then items are one level lower.
    if (is_array($items->results)) {
      $items = $items->results;
    }

    if (is_array($items)) {
      $items = array_slice($items, 0, $this->num_items);
      foreach ($items as $item) {
        $obj = new stdClass();
        $obj->id = $item->id;
        $obj->username = is_object($item->user) ? $item->user->screen_name : $item->from_user;
        $obj->userphoto = is_object($item->user) ? $item->user->profile_image_url : $item->profile_image_url;
        $obj->text = $item->text;
        //-- Convert date to unix timestamp so themer can easily work with it.
        $obj->timestamp = strtotime($item->created_at);
        $tweets[] = $obj;
      }
    }

    $this->tweets = $tweets;
  }

}
