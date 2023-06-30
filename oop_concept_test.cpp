
#include "oop_concept_test.h"

WaterVehicle::WaterVehicle(int fuel_cap, int w_power, string fuel_type, int kargo)
{
    fuelcapacity = fuel_cap;
    power = w_power;
    set_fueltype(fuel_type);
    kargo_capacity = kargo;
}

void Vehicle :: set_fueltype (string k)
{
    fuel_type = k;
}

string Vehicle :: get_fueltype ()
{
    return fuel_type;
}

void LandVehicle :: set_land_vehicle ()
{
    cout << "enter the fuel capacity:"<< endl;
    cin >> fuelcapacity;
    cout << "enter the power of vehicle: " << endl;
    cin >> power;
    cout << "enter the fuel type: " << endl;
    string s;
    cin >> s;
    set_fueltype(s);
    cout << "enter the max torque: ";
    cin >> torque;
    cout << endl;
}


int LandVehicle :: max_speed()
{
    int result = ((power* 735) / torque);
    return result;
}

int WaterVehicle :: max_speed (int knots)
{
    return ((knots * knot)/30);
}


int oop_concept_main ()
{
    
    LandVehicle car;
    
    LandVehicle bus;
    
    WaterVehicle ship (30, 1000, "diesel", 40000);
    
    
    cout << "car details: " << endl;
    car.set_land_vehicle ();
    cout << "Bus detail: " << endl;
    bus.set_land_vehicle ();
    
    
    int car_maxspeed = car.max_speed();
    int ship_maxspeed = ship.max_speed(15);
    cout << "max speed of car: " << car_maxspeed << endl<<" max speed of ship: " << ship_maxspeed << endl;
       
    
    return 0;
}


#ifndef RELOCATABLE_OBJ

int main ()
{
    oop_concept_main ();
}

#endif //RELOCTABLE_OBJ

