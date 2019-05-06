#!/usr/bin/env python

import time
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

NUM_OBJ = 64
networks = {} 
subnets = {}
rid = 0
r = {}
r_id = {}

def create_nets():
    network = {'name': '', 'admin_state_up': True}
    for i in range(1,NUM_OBJ):
        network['name'] = 'net-%d' % (i)
        print network['name']
        netw = neutron.create_network({'network':network}) 
        networks[i] = netw['network']['id']
        print networks[i]
        time.sleep(0.5)

def create_subnets():
    subnet = {'name': '', 'ip_version': 4}
    for i in range(1,NUM_OBJ):
        subnet['name'] = 'sub-%d' % (i)
        subnet['network_id'] = networks[i]
        subnet['cidr'] = '1.1.%d.1/24' % (i)
        print subnet['name']
        sub = neutron.create_subnet({'subnet':subnet}) 
        subnets[i] = sub['subnet']['id']
        print subnets[i]

def create_router():
    rtr = {'name': 'vrouter'}
    r = neutron.create_router({'router':rtr}) 
    rid = r['router']['id']
    r_id[1] = rid
    print rid

def create_intfs():
    intf = {}
    for i in range(1,NUM_OBJ):
        intf['subnet_id'] = subnets[i]
        neutron.add_interface_router(r_id[1], intf) 

if __name__ == '__main__':
    print "hello there"
    create_nets()
    create_subnets()
    create_router()
    create_intfs()
sys.exit(1) 
