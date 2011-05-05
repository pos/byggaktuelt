<?php
// $Id: block.tpl.php,v 1.1.2.1 2010/03/31 18:49:09 inadarei Exp $
?>
<div class="clearfix" id="block-<?php print $block->module .'-'. $block->delta; ?>" class="block block-<?php print $block->module ?>">

  <?php if (!empty($block->subject) && $block->module != 'views'): ?>
    <h2><?php print "$block->subject"; ?></h2>
  <?php endif;?>

  <div class="content">
    <?php print $block->content ?>
  </div>

</div>
