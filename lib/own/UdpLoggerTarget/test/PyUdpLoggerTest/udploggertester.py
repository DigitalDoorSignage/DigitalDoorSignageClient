# This example code is in the Public Domain (or CC0 licensed, at your option.)

# Unless required by applicable law or agreed to in writing, this
# software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
# CONDITIONS OF ANY KIND, either express or implied.

# -*- coding: utf-8 -*-

import socket
#import sys
import time
import threading

# -----------  Config  ----------
IP_VERSION = 'IPv4'
SERVER_PORT = 41234
CLIENT_PORT = 41235
BROADCAST_ADDRESS = '192.168.0.255'
# -------------------------------

def runServer():
    family_addr = socket.AF_INET
    f=open("log.csv","a+")

    try:
        sock = socket.socket(family_addr, socket.SOCK_DGRAM)
        sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    except socket.error as msg:
        print('Failed to create socket. Error Code : ' + str(msg[0]) + ' Message ' + msg[1])
        return

    try:
        sock.bind(('', SERVER_PORT))
    except socket.error as msg:
        print('Bind failed. Error: ' + str(msg[0]) + ': ' + msg[1])
        return

    while True:
        try:
            print('Waiting for data...')
            data, addr = sock.recvfrom(1024)
            if not data:
                break
            data = data.decode()
            line = addr[0] + ':' + str(addr[1]) + ';' + data
            print(line)
            f.write(line+"\n")
            f.flush()
            # reply = 'OK ' + data
            # sock.sendto(reply.encode(), addr)
        except socket.error as msg:
            print('Error Code : ' + str(msg[0]) + ' Message ' + msg[1])

    sock.close()
    f.close()
    return

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

def runClient():
    host = BROADCAST_ADDRESS
    family_addr = socket.AF_INET

    try:
        sock = socket.socket(family_addr, socket.SOCK_DGRAM)
    except socket.error:
        print('Failed to create socket')
        return

    while True:
        msg = get_ip()
        try:
            sock.sendto(msg.encode(), (host, CLIENT_PORT))
            reply, addr = sock.recvfrom(128)
            if not reply:
                break
            print('Reply[' + addr[0] + ':' + str(addr[1]) + '] - ' + str(reply))
        except socket.error as msg:
            print('Error Code : ' + str(msg[0]) + ' Message: ' + msg[1])
            return
        time.sleep( 5 )
    return

if __name__ == "__main__":
    serverThread = threading.Thread(target=runServer)
    clientThread = threading.Thread(target=runClient)
 
    serverThread.start()
    clientThread.start()
 
    serverThread.join()
    clientThread.join()
 
    # both threads completely executed
    print("Done!")
