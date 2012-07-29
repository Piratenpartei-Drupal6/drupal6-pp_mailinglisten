<?php

/**
 * Admin menu page for the basic settings
 */
function pp_mailinglisten_admin_form() {
  $form = array();

  
  $form['wiki_url'] = array(
    '#type' => 'fieldset',
    '#title' => t('Wiki-Einstellungen'),
    '#description' => t('Die Zahlen der Mitgliedsdaten werden aus dem Wiki geholt und dargestellt.'),
  );

  $form['wiki_url']['pp_mailinglisten_url'] = array(
    '#type' => 'textfield',
    '#title' => t('API-URL (z.B. wiki.piratenpartei.de/wiki/api.php)'),
    '#default_value' => variable_get('pp_mailinglisten_url', NULL),
  );

  $form['wiki_url']['pp_mailinglisten_site'] = array(
    '#type' => 'textfield',
    '#title' => t('Seite (z.B. HE:Mailinglisten)'),
    '#default_value' => variable_get('pp_mailinglisten_site', NULL),
  );

  $form['wiki_url']['pp_mailinglisten_user'] = array(
    '#type' => 'textfield',
    '#title' => t('Wiki-Benutzername'),
    '#default_value' => variable_get('pp_mailinglisten_user', NULL),
  );

  $form['wiki_url']['pp_mailinglisten_password'] = array(
    '#type' => 'textfield',
    '#title' => t('Wiki-Passwort'),
    '#default_value' => variable_get('pp_mailinglisten_password', NULL),
  );

  $form['wiki_url']['pp_mailinglisten_stats_url'] = array(
    '#type' => 'textfield',
    '#title' => t('URL zum XML-File (z.B. www.piratenpartei-hessen.de/stats.xml.php)'),
    '#default_value' => variable_get('pp_mailinglisten_stats_url', NULL),
  );
  
  
  $form['stats'] = array(
    '#type' => 'fieldset',
    '#title' => t('Statistik'),
    '#description' => t('Daten des letzten Laufes.'),
  );
  
  $form['stats']['last_run'] = array(
    '#type' => 'item',
    '#title' => t('Datum'),
    '#description' => date("d.m.Y H:i:s", variable_get('pp_mailinglisten_last_run', NULL)),
  );
  
  $form['stats']['checksum'] = array(
    '#type' => 'item',
    '#title' => t('Checksum'),
    '#description' => variable_get('pp_mailinglisten_checksum', NULL),
  );
  
  
  return system_settings_form($form);
}