<?php
/**
 * @file
 * Functions to preserve request/response information for UPS XML certification.
 */

/**
 * Generic function to capture request and response XML for certification
 *
 * @param $request
 *   The raw XML request sent to UPS.
 * @param $resp
 *   The raw XML response sent by UPS.
 * @param $folder
 *  A string containing the name of the folder to store the output XML files.
 * @param $name
 *   An arbritrary string indicating the type of request. The files storing the
 *   captured XML data are named using this string.
 */
function uc_ups_certification_capture_xml($request, $response, $folder, $name) {
  if (file_check_directory(file_create_path('ups_certification'), FILE_CREATE_DIRECTORY)) {
    if (file_check_directory(file_create_path('ups_certification/' . $folder), FILE_CREATE_DIRECTORY)) {
      $xml_request_path = file_create_path('ups_certification/' . $folder) .'/' . $name . 'Request.xml';
      $xml_response_path = file_create_path('ups_certification/' . $folder) .'/' . $name . 'Response.xml';
    
      // need to get rid of the UPS access request that has the user name and
      // password this is the first xml document in $request, but I'm not sure why
      // explode puts it in the second array
      $new_request = $request;
      $new_request_array = explode('<?xml version="1.0" encoding="UTF-8"?>', $request);
      $new_request = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" . $new_request_array[2];
    
      if ($xml_request_file = fopen($xml_request_path, 'wb')) {
        fwrite($xml_request_file, $new_request);
        fclose($xml_request_file);
        drupal_set_message(t('Wrote XML request to file %filename', array('%filename' => $xml_request_path)));
      }
      else {
        drupal_set_message(t('Could not open a file to save the request XML document.'), 'error');
      }
    
      if ($xml_response_file = fopen($xml_response_path, 'wb')) {
        fwrite($xml_response_file, $resp->data);
        fclose($xml_response_file);
        drupal_set_message(t('Wrote XML response to file %filename', array('%filename' => $xml_response_path)));
      }
      else {
        drupal_set_message(t('Could not open a file to save the response XML document.'), 'error');
      }
    }
    else {
      drupal_set_message(t('Could not find or create the directory %folder in the site files directory.', array('%folder' => 'ups_certification/' . $folder)), 'error');
    }
  }
  else {
    drupal_set_message(t('Could not find or create the directory %folder in the site files directory.', array('%folder' => 'ups_certification')), 'error');
  }
}

/**
 * Capture label image data of a package shipment for certification
 *
 * @param $html_page
 *   The base64-encoded HTML page containing the label image sent back by UPS.
 * @param $label_image
 *   The base64-encoded image data sent back by UPS.
 * @param $folder
 *  A string containing the name of the folder to store the output XML files.
 * @param $tracking_number
 *   The tracking number of a package. The files storing the captured XML data
 *   are named using this string.
 */
function uc_ups_certification_capture_label_image($html_page, $label_image, $folder, $tracking_number) {
  if (file_check_directory(file_create_path('ups_certification'), FILE_CREATE_DIRECTORY)) {
    if (file_check_directory(file_create_path('ups_certification/' . $folder), FILE_CREATE_DIRECTORY)) {
      $label_path = file_create_path('ups_certification/' . $folder) .'/label' . $tracking_number . '.gif';
      $html_path = file_create_path('ups_certification/' . $folder) .'/' . $tracking_number . '.html';

      if ($label_file = fopen($label_path, 'wb')) {
        fwrite($label_file, base64_decode($label_image));
        fclose($label_file);
        drupal_set_message(t('Wrote label image file %filename', array('%filename' => $label_path)));
      }
      else {
        drupal_set_message(t('Could not open a file to save the label image.'), 'error');
      }
  
      if ($html_file = fopen($html_path, 'wb')) {
        fwrite($html_file, base64_decode($html_page));
        fclose($html_file);
        drupal_set_message(t('Wrote HTML page to file %filename', array('%filename' => basename($html_path), '@folder' => 'ups_certification/' . $folder)));
      }
      else {
        drupal_set_message(t('Could not open a file to save %filename.', array('%filename' => $html_path)), 'error');
      }
    }
    else {
      drupal_set_message(t('Could not find or create the directory %folder in the site files directory.', array('%folder' => 'ups_certification/' . $folder)), 'error');
    }
  }
  else {
    drupal_set_message(t('Could not find or create the directory %folder in the site files directory.', array('%folder' => 'ups_certification')), 'error');
  }
}

/**
 * Captures the high-value report HTML page sent back by UPS.
 *
 * @param $receipt
 *   The ControlLogReceipt data sent back by UPS after a ShipAccept request.
 * @param $folder
 *   A string containing the name of the folder to store the output XML files.
 */
function uc_ups_certification_capture_high_value($receipt, $folder) {
  if (isset($receipt)) {
    if (file_check_directory(file_create_path('ups_certification/' . $folder), FILE_CREATE_DIRECTORY)) {
      $html_path = file_create_path('ups_certification/' . $folder) . '/high-value-report.html';
      $html_image = $receipt->GraphicImage;
      if ($html_file = fopen($html_path, 'wb')) {
        fwrite($html_file, base64_decode($html_image));
        fclose($html_file);
        drupal_set_message(t('Wrote high value report to %file', array('%file' => $html_path)));
      }
      else {
        drupal_set_message(t('Could not open a file to save the high value report.', array('@filename' => basename($html_path))), 'error');
      }
    }
    else {
      drupal_set_message(t('Could not find or create the directory %folder in the site files directory.', array('%folder' => 'ups_certification/' . $folder)), 'error');
    }
  }
}
