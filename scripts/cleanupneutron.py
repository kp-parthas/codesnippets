#!/usr/bin/env python

import os
import sys
import neutronclient.v2_0.client as nclient

def get_credentials():
    d = {}
    d['username'] = os.environ['OS_USERNAME']
    d['password'] = os.environ['OS_PASSWORD']
    d['auth_url'] = os.environ['OS_AUTH_URL']
    d['tenant_name'] = os.environ['OS_TENANT_NAME']
    return d

credentials = get_credentials()
neutron = nclient.Client(**credentials)

def del_neutron_objects(object):
    type = object[:-1]
    print type
    objects = getattr(neutron, 'list_' + object)()
    for obj in objects.get(object):
        id = obj['id']
        getattr(neutron, 'delete_' + type)(id)

if __name__ == '__main__':
    print "hello there"
    objects = [ 'routers', 'subnets', 'networks' ]
    for object in objects:
        del_neutron_objects(object)
sys.exit(1) 
