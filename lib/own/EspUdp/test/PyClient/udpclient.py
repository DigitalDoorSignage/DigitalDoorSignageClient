# This example code is in the Public Domain (or CC0 licensed, at your option.)

# Unless required by applicable law or agreed to in writing, this
# software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
# CONDITIONS OF ANY KIND, either express or implied.

# -*- coding: utf-8 -*-

import socket
import sys
import time
import socket

def get_ip():
    s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    try:
        # doesn't even have to be reachable
        s.connect(('10.255.255.255', 1))
        IP = s.getsockname()[0]
    except:
        IP = '127.0.0.1'
    finally:
        s.close()
    return IP

# -----------  Config  ----------
PORT = 41235
IP_VERSION = 'IPv4'
IPV4 = '192.168.0.255'
IPV6 = 'FE80::32AE:A4FF:FE80:5288'
# -------------------------------

if IP_VERSION == 'IPv4':
    host = IPV4
    family_addr = socket.AF_INET
elif IP_VERSION == 'IPv6':
    host = IPV6
    family_addr = socket.AF_INET6
else:
    print('IP_VERSION must be IPv4 or IPv6')
    sys.exit(1)


try:
    sock = socket.socket(family_addr, socket.SOCK_DGRAM)
except socket.error:
    print('Failed to create socket')
    sys.exit()

while True:
    hostname = socket.gethostname()    
    IPAddr = socket.gethostbyname('fritz.box') 
    msg = get_ip()
    try:
        sock.sendto(msg.encode(), (host, PORT))
        reply, addr = sock.recvfrom(128)
        if not reply:
            break
        print('Reply[' + addr[0] + ':' + str(addr[1]) + '] - ' + str(reply))
    except socket.error as msg:
        print('Error Code : ' + str(msg[0]) + ' Message: ' + msg[1])
        sys.exit()
    time.sleep( 5 )

