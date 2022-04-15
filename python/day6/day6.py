with open("./intro.txt") as f:
    x = [str(x) for x in f.read().split()]
    print(len(x))
#f.read() 
#input()
# a file stream including some stringsk