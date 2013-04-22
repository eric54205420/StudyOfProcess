if __name__ == '__main__':
	import socket
	sock = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
	sock.bind(('localhost',1211))
	sock.listen(10)
	while True:
		connection,address = sock.accept()
		try:
			connection.settimeout(5)
			buf = connection.recv(1024)
			print buf
			connection.send('Send Success!')
		except socket.timeout:
			print 'time out'
		connection.close()
