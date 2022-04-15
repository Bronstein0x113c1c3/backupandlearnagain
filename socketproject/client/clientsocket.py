from socket import *
host  = input("Write the host address you want to connect: ")
port = int(input("Write the port you want to connect: "))
client  = socket(AddressFamily.AF_INET,SocketKind.SOCK_STREAM)
client.connect((host,port))
while True:
    a = client.recv(1024).decode(encoding='UTF-8')
    print(a)
    if (a=="quit"):
        client.close()
