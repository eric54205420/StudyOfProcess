if __name__ == '__main__':
	import socket
	sock = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
	sock.connect(('localhost',1211))
	sock.send('2010201211')
	print sock.recv(1024)
	sock.close()

