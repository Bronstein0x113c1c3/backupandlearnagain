x = int(input())
if (x%5==0):
    result = x//5
else:
    result  = (x-x%5)//5+1
print(result)