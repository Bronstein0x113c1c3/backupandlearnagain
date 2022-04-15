#args here: Convert the arguments into list type.
def say(*args):
    print("Hello, I'm {0}".format(args[0]))
say("Bronstein")
#kwargs here: Convert the argument into tuple type.
def say(**kwargs):
    print("Hello everybody, I'm {name}, I'm {age} years old".format(name = kwargs["name"],age = kwargs["age"]))

name = input("Name: ")
age = int(input("Age: "))
say(name = name, age = age)