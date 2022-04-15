class Car:
    wheels = 0    #public variable 
    capacity = 0
    _a = 2     #private variable (with "_<name>")
    def __init__(self) -> None:  # contructor
        print("Car is created")
    def info(self): #some methods
        print(self._a)
car1 = Car()
car1.info()
