foods = []
#assign value to variable as part of a larger expression
"""
while (food:=input("What food do you like: "))!="quit":
    foods.append(food)
print(foods)
"""

#------------------
#a:=5>3
#print(a)
lists = [4,6,3,2,1]
after = []
for element in lists:
    if (x:=element)>=3:
        after.append(x)
    print(after)