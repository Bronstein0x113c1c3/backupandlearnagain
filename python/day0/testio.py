lists = []
with open('test.txt', 'r') as f:
   a = f.readline()
   while line:=f.readline(): #walrus operator
      lists.append([x for x in line.split()])
   
print(lists)
