"""
-Abstract method or class using for fixating what 
other inherited classes must do. In C#, it can be called
as "interface". An abstract class is the intersection of
class and interface
-An abstract class can't be instantiated


"""

from abc import ABC, abstractmethod
class Vehicle(ABC):
    @abstractmethod
    def go(self):
        pass
    @abstractmethod
    def stop(self):
        pass
class Car(Vehicle):
    def go(self):
        print("Drving the car")
    def stop(self):
        print("Stopping")

try:
    car_1 = Car()
    car_1.go()
    car_1.stop()
except Exception as e:
    print(e)