<?php
/**
 * @return array
 * CONTENT API FUNCTION
 */
function content_api($bundle, $id = null)
{
    $webservice = new WebserviceController();

    //Implementation of basic auth
    if (false) {
        header('HTTP/1.0 401 Unauthorized');
    } else {
        require_once DRUPAL_ROOT . '/' . variable_get('password_inc', 'includes/password.inc');
        $data = array();

        //Validate username and password
        if (true) {
            if (!isset($_SERVER['HTTP_CHECKSUM'])) {
                header('HTTP/1.0 401 Unauthorized');
            } else {
                // Response array for api call
                $response = array();
                $checksum = '';
                if (isset($_SERVER['HTTP_CHECKSUM'])) {
                    $checksum = $_SERVER['HTTP_CHECKSUM'];
                }
                $flag = $webservice->verify_checksum($checksum);

                if (!$flag) {
                    header('HTTP/1.0 401 Unauthorized');
                } else {
                    switch ($_SERVER['REQUEST_METHOD']) {
                        case 'GET':
                            try {

                                // LOGIC FOR PAGINATION CALCULATION BY GET DATA PAGE AND LIMIT
                                $page = 1; // Initialize default page as 1
                                $limit = 10;// Initialize default limit as 10
                                $offset = 0;// Initialize default offset as 0

                                if(isset($_GET['page'])){
                                    $page = $_GET['page'];// Set page number if isset
                                }
                                if(isset($_GET['limit'])){
                                    $limit = $_GET['limit'];
                                    $offset = (intval($page)-1)*$limit;
                                    $limit = (intval($limit));
                                }
                                // LOGIC FOR PAGINATION CALCULATION BY GET DATA PAGE AND LIMIT

                                $data = [];
                                //Check if id is set to determine whether to generate a list or single node values
                                if (!empty($id)) {
                                    $objects = $webservice->bundle_load('node', $bundle, 'type', array($id), array());
                                } else {
                                    $objects = $webservice->bundle_load('node', $bundle, 'type', null, array('offset' => $offset, 'limit' => $limit));
                                }
                                if (!empty($objects)) {
                                    //Iterate over objects
                                    foreach ($objects as $key => $val) {
                                        $get_required_info['id'] = $val->nid;
                                        $get_required_info['title'] = $val->title;
                                        $get_required_info['date'] = $val->changed;

                                        if (!empty($val->body['und'][0]['value'])) {
                                            $get_required_info['body'] = $val->body['und'][0]['value'];
                                        }


                                        $data[] = $get_required_info;
                                    }
                                }
                                $response['success'] = 1;
                                $response['message'] = 'Successful';
                            } catch (Exception $e) {
                                $response['success'] = 0;
                                $response['message'] = 'Exception occurred';
                            }
                            $response['data'] = $data;
                            echo json_encode($response);
                            break;

                        case 'POST':
                            header('HTTP/1.0 405 Method not allowed');
                            break;

                        case 'PUT':
                            header('HTTP/1.0 405 Method not allowed');
                            break;

                        case 'DELETE':
                            header('HTTP/1.0 405 Method not allowed');
                            break;

                        default:
                            header('HTTP/1.0 405 Method missing');
                            break;
                    }
                } // Verify is checksum is valid
            } // Verify if checksum is set
            //RESTful implementation
        } else {
            header('HTTP/1.0 401 Unauthorized');
        }
    }
}