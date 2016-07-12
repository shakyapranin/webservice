# Webservice Module 0.1.0

Module that exposes drupal entities to RESTful APIs.

# Supports Drupal 7.x

# Dependencies

1. cors module<br>
    [cors](https://www.drupal.org/project/cors)

# Module Usage

1. <b>Git clone</b> {git_url} or download zip.<br>
2. <b>Rename</b> 'webservice-master' to 'webservice'.<br>
3. <b>Copy</b> folder to sites/all/modules.<br>
4. <b>Enable</b> module.<br>
5. Setup <b>CORS</b> module from = admin/config/services/cors <br>
    Place <b>'api/v1/*|*|GET,OPTIONS|Content-Type,Checksum|True'</b> inside Domains field and Save configuration.<br>
    The controls can be modified as per need.<br>
6. <b>Clear drupal cache.</b><br>

# Considerations before using the <b>API</b>

1. By default the <b>checksum</b> header for the APIs are md5 hash of the allowed domain name.

    For example : you placed the entry <b>'api/v1/*|example.com|GET,OPTIONS|Content-Type,Checksum|True'</b> in the Domains field.<br>
    Your hash will be : <i>1a79a4d60de6718e8e5b326e338ae533</i> i.e. a md5 hass of the domain name 'example'.

# <b>API</b> usage

1. <b>Access APIs</b> using <br>

    GET <i>http://{drupal_instance}/api/v1/content/{bundle_name}</i> <br>
    HEADERS 'checksum' = {your_checksum}

    By default drupal ships with : article and page so the APIs would be <br>

    GET <i>http://{drupal_instance}/api/v1/content/article</i> <br>
    HEADERS 'checksum' = {your_checksum}<br>

    GET <i>http://{drupal_instance}/api/v1/content/article/{id}</i> <br>
    HEADERS 'checksum' = {your_checksum}<br>

2. Offset and limit can be used as <br>

    GET <i>http://{drupal_instance}/api/v1/content/article?page={page number}&&limit={numeric value}</i> <br>
    HEADERS 'checksum' = {your_checksum}<br>

    <b><i>NOTE: To remove any further confusions on checksum refer Consideration before using the <b>API</b> section</i></b>

# Additional information for <b>CORS</b> module

A list of paths and corresponding domains to enable for CORS. Multiple entries should be separated by a comma. Enter one value per line separated by a pipe, in this order:<br>
Internal path<br>
Access-Control-Allow-Origin. Use <mirror> to echo back the Origin header.<br>
Access-Control-Allow-Methods<br>
Access-Control-Allow-Headers<br>
Access-Control-Allow-Credentials<br>
Examples:<br>
*|http://example.com<br>
api|http://example.com:8080 http://example.com<br>
api/*|<mirror>,https://example.com<br>
api/*|<mirror>|POST|Content-Type,Authorization|true<br>