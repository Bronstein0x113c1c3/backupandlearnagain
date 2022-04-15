def sort(arr):
    for i in range(len(arr)):
        for j in range(i+1, len(arr)):
            if arr[i] < arr[j]:
                arr[i], arr[j] = arr[j], arr[i]
    return arr
def main():
    arr = [int(x) for x in input().split()]
    print(sort(arr))
main()