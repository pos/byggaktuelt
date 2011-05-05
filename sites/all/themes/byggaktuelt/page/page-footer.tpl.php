<?php
// $Id: page-footer.tpl.php,v 1.1 2010/09/21 12:57:34 pos Exp $
/**
 * @file page-footer.tpl.php
 * Footer template.
 *
 * For the list of available variables, please see: page.tpl.php
 *
 * @ingroup page
 */
?>

      </div> <!-- /#container -->
     
   </div>   <!-- Internal wrapper -->
     <?php if ($ad): ?>
           <div  id="sidebar-ad"><div id="sidebar-ad-inner" class="region region-ad">
              <?php print $ad; ?>
          </div></div> <!-- /#sidebar-ad-inner, /#sidebar-ad -->
    <?php endif; ?>
    </div> <!-- /#wrapper -->
   
        <div class="clear"></div>	
         	
        <div id="footer" class="clearfix clear">
        <div id="footer-links-wrapper">
          <div id="footer-menu-primary"><?php print menu_tree('menu-footer-primary'); ?></div>
          <div id="footer-feed-icon"><a href="<?php print url('rss/articles/all'); ?>"><img src="/misc/feed.png" width="16" height="16" alt="<?php print t('Get the main site RSS feed'); ?>"/></a></div>
          <div id="footer-menu-secondary"><?php print menu_tree('menu-footer-secondary'); ?></div>
        </div><!--/footer-links-wrapper-->
          
          <?php print $footer_message . $footer ?>          
        </div> <!-- /#footer -->
      
 
  </div> <!-- /#outer-wrapper -->
 
  <!-- /layout -->
  <?php print $closure ?>
</body>
</html>
