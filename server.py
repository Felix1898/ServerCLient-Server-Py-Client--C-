import socket                   # Importing socket module!

port = 60000                    # Reserving a port for your service.
s = socket.socket()             # Creating a socket object
host = "127.0.0.1"     # Getting local machine name
s.bind((host, port))            # Binding to the port
s.listen(5)                     # Now waiting.... for client connection.
i=0
print 'Server listening....'
list1=list()
while True:
    conn, addr = s.accept()     # Establishing... connection with client.
    print 'Got connection from', addr
    data = conn.recv(1024) 
    print('Server received', repr(data))

    filename=data
    f = open(filename,'rb')
    l = f.read(1)
    c=''
    while (l):
       if (ord(l)>47 and ord(l)<58 and int(l) not in list1): 
        list1.append(int(l));
       list1.sort()
       stringof= ""
       for i in list1:
         stringof+= str(i)

      
       print('Sent ',repr(stringof))
       l = f.read(1)
    conn.send(stringof)   
    f.close()

    print('Done sending')
    conn.send('     Thanks for connecting')
    conn.close()

