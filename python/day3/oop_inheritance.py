class Car:
    wheel = None
    def __init__(self, wheel):
        self.wheel = wheel
        print('car is creating')
    def operate(self):
        print("pi pi pi")
class Sedan(Car):
    def __init__(self, name):
        #Car.wheel = 4
        super().__init__(4)
        self.name = name
        print("this car is sedan-type, its name is {0} and it had {1} wheels".format(name,Car.wheel))
    def operate(self):
        print("po po po")
class Truck(Car):
    def __init__(self, name):
        #Car.wheel = 6
        super().__init__(6)
        self.name = name
        print('this car is truck, its name is {0} and it has {1} wheels'.format(name,Car.wheel))
    def operate(self):
        print("no honk :>>")
"""
Some conclusion:
-Inheriting using parent class variable
-Before using parent class variable, we must init using constructor, with <parent_class>.<variable>
-Beside, we can use super() to access to the methods of a parent class
-We see "operate" overrided
"""


car_1 = Sedan("BMW")
car_2 = Truck("Chervolet")
car_1.operate()
car_2.operate()


