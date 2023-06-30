#ifndef _OOP_CONCEPT_TEST_H_
#define _OOP_CONCEPT_TEST_H_

#include <bits/stdc++.h>

using namespace std;

class Vehicle
{
    public:
        
        int fuelcapacity;
        int power;
        
    private:
        string fuel_type;
    
    public:
        int max_travel_dist ();  
        void set_fueltype (string k);
        string get_fueltype ();           
};

class LandVehicle : public Vehicle
{
    public:
        
        void set_land_vehicle ();
        int torque;
        int max_speed();
        int payload (int passenger);
        int payload (float load);
        
};

class WaterVehicle : public Vehicle
{
    public:
    
        int kargo_capacity;
        int knot = 1852;
        
        WaterVehicle (int fuel_cap, int w_power, string fuel_type, int kargo );
        
        int max_speed (int knots);
        void set_water_vehicle ();
   
};

#endif //_OOP_CONCEPT_TEST_H_

