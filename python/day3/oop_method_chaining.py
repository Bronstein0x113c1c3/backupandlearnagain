class Car:
    wheels = None
    def __init__(self,name,color,type):
        self.name = name  #declare variable in constructor
        self.color = color
        self.type = type
    #declare chaining method: new method.
    #------------------------------------------------------
    def turn_on(self):
        print('Car is on')
        return self
    def drive(self):
        print('Car is driving')
        return self
    def brake(self):
        print('Car is braking')
        return self
    def turn_off(self):
        print('Car is off')
        return self
    #------------------------------------------------------
    """
    declare method chaining: old method.
    def turn_on(self):
        print("car is on")
        drive()
    def drive(self):
        print("car is driving")
        brake()
    def brake(self):
        print("car is braking")
        turn_off(self)
    def turn_off(self):
        print("car is off")
    """
    
car1 = Car("BMW","red","sedan")
car1.turn_on().drive().brake().turn_off()