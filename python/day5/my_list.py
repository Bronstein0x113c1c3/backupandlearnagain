
def calculate(my_list):
    a = 0
    b = 1
    for m in my_list:
        if m%2==0:
            b*=m
        else:
            a+=m
    return (a,b)
my_list = [int(x) for x in input().split()]
print(calculate(my_list))