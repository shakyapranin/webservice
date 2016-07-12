# Webservice Module 0.1.0

Module that exposes drupal entities to RESTful APIs.

# Supports Drupal 7.x

# Dependencies

1. cors module<br>
    [cors](https://www.drupal.org/project/cors)

# Usage

1. <b>Git clone</b> {git_url} or download zip.<br>
2. <b>Rename</b> 'webservice-master' to 'webservice'.<br>
3. <b>Copy</b> folder to sites/all/modules.<br>
4. <b>Enable</b> module.<br>
5. Setup <b>CORS</b> module from = admin/config/services/cors <br>
    Place 'api/v1/*|*|GET,OPTIONS|Content-Type,Checksum|True' inside Domains field and Save configuration.<br>
    The controls can be modified as per need.<br>
6. <b>Clear drupal cache.</b><br>
7. <b>Access APIs</b> using <br>

    <i>http://{drupal_instance}/api/v1/content/{bundle_name}</i> <br>

    By default drupal ships with : article and page so the APIs would be <br>

    GET <i>http://{drupal_instance}/api/v1/content/article</i> <br>
    GET <i>http://{drupal_instance}/api/v1/content/article/{id}</i> <br>

8. Offset and limit can be used as <br>

    GET <i>http://{drupal_instance}/api/v1/content/article?page={page number}&&limit={numeric value}</i> <br>