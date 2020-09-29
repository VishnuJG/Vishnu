import socket

s = socket.socket()
port = 9999
host = "192.168.0.121"
s.connect((host, port))