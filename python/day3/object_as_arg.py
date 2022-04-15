class Vehicle:
    color = None
class Car(Vehicle):
    pass
class Motocycle(Vehicle):
    pass
def change_color(vehicle,color):
    vehicle.color = color

ve_1 = Car()
change_color(ve_1,"yellow")
print(ve_1.color)