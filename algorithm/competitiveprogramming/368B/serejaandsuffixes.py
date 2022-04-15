list_element = []
x,y = [int(m) for m in input().split()]


arr = [int(x) for x in input().split()]
dp = [0 for x in range(0,len(arr))]
dp[len(arr)-1] = 1
list_element.append(arr[len(arr)-1])
indice = len(arr)-2
while (indice>=0):
    if list_element.__contains__(arr[indice])==False:
        dp[indice] = dp[indice+1]+1
        list_element.append(arr[indice])
    else:
        dp[indice] = dp[indice+1]
    indice-=1
for i in range(0,y):
    m = int(input())
    print(dp[m-1])