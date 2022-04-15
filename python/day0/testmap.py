lists = []
with open("test.txt","r") as f:
    w = f.readline()
    while line := f.readline():
        test = list(map(int,line.split()))
        print(test)
#map is used for ilterate each element in line with a function
#such as int(), list(),...