<?php
/**
 * @file
 * off_image_feature.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function off_image_feature_field_default_field_instances() {
  $field_instances = array();

  // Get a list of content types that should have the field_topics field added.
  $entity_types = off_image_feature_get_entity_types_with_image();
  if (!empty($entity_types)) {
    foreach ($entity_types as $entity_type => $bundles) {
      foreach(array_keys($bundles) as $bundle) {
        off_image_feature_field_definition($field_instances, $entity_type, $bundle);
      }
    }
  }

  // Translatables
  // Included for use with string extractors like potx.
  t('Image');

  return $field_instances;
}

function off_image_feature_field_definition(&$field_instances, $entity_type, $bundle) {
  // Exported field_instance: 'ENTITY_TYPE-BUNDLE-field_image'
  $field_instances["$entity_type-$bundle-field_image"] = array(
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => 'medium',
        ),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => 'content',
          'image_style' => 'thumbnail',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
    ),
    'entity_type' => $entity_type,
    'field_name' => 'field_image',
    'label' => 'Image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '4 MB',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'media',
      'settings' => array(
        'allowed_schemes' => array(
          'private' => 'private',
          'public' => 'public',
        ),
        'allowed_types' => array(
          'audio' => 0,
          'default' => 0,
          'image' => 'image',
          'video' => 0,
        ),
        'progress_indicator' => 'throbber',
      ),
      'type' => 'media_generic',
      'weight' => 32,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Image');

  return $field_instances;
}
