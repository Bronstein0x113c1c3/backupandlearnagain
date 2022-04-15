from socket import *
import os
server = socket(AddressFamily.AF_INET,SocketKind.SOCK_STREAM)
server.bind(("",8080))
server.listen(3)
print("waiting for incoming connection\n")
client,clientaddr = server.accept()
while True:
    sentence = input("write something here: ")
    client.send(sentence.encode(encoding="utf-8"))
    if (sentence == "quit"):
        client.close()
