def insertionsort(arr):
    print(arr)
    for j in range(1,len(arr)):
        key = arr[j]
        i = j - 1
        while (i>=0) and (arr[i]>key):
            arr[i+1], arr[i] = arr[i],arr[i+1]
            key = arr[i]           
            i-=1
        print(arr)
    pass
arr = [5,2,4,6,1,3]
insertionsort(arr)
print(arr)
