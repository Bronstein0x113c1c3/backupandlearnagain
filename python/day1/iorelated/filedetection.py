import os
path = "C:\\Windows\\System32"
if os.path.exists(path):
    print("System folder")
if os.path.isfile(path):
    print("file is here")
if os.path.isdir(path):
    print("this is a directory")