<?php
// $Id: block.tpl.php 7118 2010-04-15 18:27:08Z jeremy $
?>

<div id="block-<?php print $block->module .'-'. $block->delta; ?>" class="block block-<?php print $block->module ?> <?php print $block_zebra; ?> <?php print $position; ?> <?php print $skinr; ?>">
  <div class="inner clearfix">
    <?php if (isset($edit_links)): ?>
    <?php print $edit_links; ?>
    <?php endif; ?>
    <div class="extra-bg"><div class="extra-bg-inner">
      <?php if ($block->subject): ?>
      <h2 class="title block-title"><?php print $block->subject ?></h2>
      <?php endif;?>
      <div class="content clearfix">
        <?php print $block->content ?>
      </div>
    </div></div><!-- /extra-bg -->
  </div><!-- /block-inner -->
</div><!-- /block -->
