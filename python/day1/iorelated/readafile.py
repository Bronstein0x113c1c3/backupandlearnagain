#use absolute path, not relative path
import os
dirname =os.getcwd()+"\\iorelated\\filehere\\test.txt"
with open(dirname,'a') as file:
    print(file.write("Hello file"))
print(os.getcwd())


