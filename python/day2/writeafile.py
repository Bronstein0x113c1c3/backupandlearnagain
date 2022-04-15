text = "Hello"
#with...as is opening then closing
with open('test.txt','w') as file:
    file.write(text)
#work with relative path
with open('./iohere/work.txt','w') as file:
    file.write(text)