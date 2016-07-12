# Webservice Module 0.1.0

Module that exposes drupal entities to RESTful APIs.

# Supports Drupal 7.x

# Dependencies

1. cors module<br>
    [cors](https://www.drupal.org/project/cors)

# Usage

1. Git clone {git_url} or download zip.<br>
2. Rename 'webservice-master' to 'webservice'.<br>
3. Place inside = sites/all/modules.<br>
4. Enable module.<br>
5. Setup CORS module from = admin/config/services/cors <br>
    Place 'api/v1/*|*|GET,OPTIONS|Content-Type,Checksum|True' inside Domains field and Save configuration.<br>
    The controls can be modified as per need.<br>
6. Clear drupal cache.<br>
7. Access APIs using http://{drupal_instance}/api/v1/content/{bundle_name} <br>
    By default drupal ships with : article and page so the APIs would be <br>

    GET http://{drupal_instance}/api/v1/content/article <br>
    GET http://{drupal_instance}/api/v1/content/article/{id} <br>

8. Offset and limit can be used as <br>

    GET http://{drupal_instance}/api/v1/content/article?page={page number}&&limit={numeric value} <br>