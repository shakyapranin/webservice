# Webservice Module

Module that exposes drupal entities to RESTful APIs.
packages = Webservice
core = 7.x
version = 0.1.0

# Dependencies

1. cors module
    [cors](https://www.drupal.org/project/cors)

# Usage

1. Git clone <git_url> or download zip.
2. Rename 'webservice-master' to 'webservice'.
3. Place inside = sites/all/modules.
4. Enable module.
5. Setup CORS module from = admin/config/services/cors
    Place 'api/v1/*|*|GET,OPTIONS|Content-Type,Checksum|True' inside Domains field and Save configuration.
    The controls can be modified as per need.
6. Clear drupal cache.
7. Access APIs using http://<drupal_instance>/api/v1/content/<bundle_name>
    By default drupal ships with : article and page so the APIs would be

    GET http://<drupal_instance>/api/v1/content/article
    GET http://<drupal_instance>/api/v1/content/article/<id>

8. Offset and limit can be used as

    GET http://<drupal_instance>/api/v1/content/article?page=<page number>&&limit=<numeric value>