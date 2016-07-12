<?php

class WebserviceController
{
    public function __construct()
    {
    }

    /**
     * @param $checksum
     * @return bool
     * Function to verify checksum
     */
    function verify_checksum($checksum)
    {
        // Flag to authorize public api call
        $flag = false;
        $cors_domains = '';
        foreach (variable_get('cors_domains', array()) as $path => $domain) {
            $cors_domains = $domain;
        }
        $cr_domains = explode(" ", $cors_domains);
        $crdomains = explode("|", $cr_domains[0]);
        $domain = $crdomains[0];
        $host = $this->get_host_from_domain($domain);
        $verified_checksum = md5($host);
        if ($checksum == $verified_checksum) {
            $flag = true;
        }
        return $flag;
    }

    /**
     * @param $entity_type
     * @param $bundleName
     * Function to load bundle data
     */
    function bundle_load($entity_type, $bundleName, $bundleKey, $ids, $range = array('offset' => 0,'limit' => 10))
    {
        $query = new EntityFieldQuery();
        $query
            ->entityCondition('entity_type', $entity_type, '=')
            ->propertyCondition($bundleKey, $bundleName, '=');
        if (!empty($ids)) {
            if ($entity_type == 'node') {
                $query->propertyCondition('nid', $ids, 'IN');
            } else {
                $query->propertyCondition('id', $ids, 'IN');
            }
        }
        if (!empty($range) && $range != 0) {
            $query->range($range['offset'], $range['limit']);
        }
        $result = $query->execute();
        $bundleNodes = array();
        if (!empty($result)) {
            $vids = array_keys($result[$entity_type]);
            $bundleNodes = entity_load($entity_type, $vids);
        }
        return $bundleNodes;
    }

    /**
     * @param $domain
     * @return mixed
     * Get the hostname from the provided domain name
     */
    function get_host_from_domain($domain)
    {
        $domain = trim($domain, '/');
        // If scheme not included, prepend it
        if (!preg_match('#^http(s)?://#', $domain)) {
            $domain = 'http://' . $domain;
        }
        $urlParts = parse_url($domain);

        // remove www
        $host = preg_replace('/^www\./', '', $urlParts['host']);
        return $host;
    }

}