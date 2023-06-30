class Vehicle:
    def __init__(self, fuelacap, wpower, fueltype):
        self.fuelCapacity = fuelacap
        self.power = wpower
        self.fuelType = fueltype


class landVehicle(Vehicle):
    def __init__(self, fuelacap, wpower, fueltype, torque):
        super().__init__(fuelacap, wpower, fueltype)
        self.torque = torque
    
    def setLandVehicle(self):
        self.fuelCapacity = int(input("Enter the fuel capacity: "))
        self.power = int(input("Enter the power: "))
        self.fuelType = input("Enter the fuel type: ")
        self.torque = int(input("Enter the torque: "))
    
    def maxSpeed(self):
        return ((self.power*785)/self.torque)
    
    def payload(self,x):
        print(self.fuelType)
    def payload(self):
        print(self.power)




class waterVehicle(Vehicle):
    def __init__(self,fuelacap,wpower,fueltype,kargo):
        super().__init__(fuelacap,wpower,fueltype)
        self.kargoCapacity = kargo
        self.knot = 1852
    
    def maxSpeed(self,knots):
        return ((self.knot * knots)/30)

car = landVehicle(0, 0, None, 0)
ship = waterVehicle(1000,600,"diesel",1200)
car.setLandVehicle()

print("max speed of car:",car.maxSpeed())
print("max speed of ship",ship.maxSpeed(12))
print(car.payload(12))


