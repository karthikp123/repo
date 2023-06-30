import java.util.*;

class Vehicle
{
    public int fuelCapacity;
    public int power;
    
    private String fuelType;
    
    public void setFuelType (String k){
     
        this.fuelType = k;
    }
    
    public String getFuelType (){
        return fuelType;
    }
}

class LandVehicle extends Vehicle {

    public int torque;
    
    Scanner sc = new Scanner (System.in);
    
    public void setLandVehicle (){
    
        System.out.print ("Enter the fuel capacity: ");
        fuelCapacity = sc.nextInt();
        
        System.out.print ("enter the power of vehicle: ");
        power = sc.nextInt();
        
        System.out.print ("enter the fuel type: ");
        String s;
        s = sc.nextLine();
        setFuelType(s);
        
        System.out.println ("enter the torque: ");
        torque = sc.nextInt();
        
    }
    
    public int maxSpeed (){
        
        return (power * 735)/torque;
        
        
    }
}

class WaterVehicle extends Vehicle{

    public int kargoCapacity;
    public int knot = 1852;
    
    public WaterVehicle (int fuelCap, int wPower, String fuelType, int kargo){
    
        fuelCapacity = fuelCap;
        power = wPower;
        setFuelType (fuelType);
        kargoCapacity = kargo;
        
    }
    
    public int maxSpeed (int knots){
        
        return ((knots * knot)/30);
    }
}

public class oopConcept
{
    public static void main (String [] args){
    
    LandVehicle car = new LandVehicle();
    /*LandVehicle bus = new LandVehicle();*/
    
    WaterVehicle ship = new WaterVehicle (30,1000,"diesel",4000);
    
    System.out.println ("ente the car details: ");
    car.setLandVehicle ();
    //bus.setLandVehicle();
    
    int carMaxSpeed = car.maxSpeed();
    int shipMaxSpeed = ship.maxSpeed(15);
    
    System.out.println ("max speed of car: "+carMaxSpeed+"\nmax ship speed: "+shipMaxSpeed);
    
    }
    
}
