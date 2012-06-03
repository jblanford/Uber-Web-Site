<?php
// $Id: template.php 7313 2010-05-11 21:29:19Z jeremy $

function fusion_technoli_preprocess_page(&$vars) {
  // Generate links tree & add Superfish class if dropdown enabled, else make standard primary links
  $vars['primary_links_tree'] = '';
  if ($vars['primary_links']) {
    if (theme_get_setting('primary_menu_dropdown') == 1) {
      $vars['primary_links_tree'] = menu_tree(variable_get('menu_primary_links_source', 'primary-links'));
      $vars['primary_links_tree'] = preg_replace('/<ul class="menu/i', '<ul class="menu sf-menu sf-navbar', $vars['primary_links_tree'], 1);
    }
    else {
      $vars['primary_links_tree'] = theme('links', $vars['primary_links'], array('class' => 'menu'));
    }
  }
}