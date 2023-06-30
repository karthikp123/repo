package main

import (
	"fmt"
)

type Vehicle struct {
	fuelCapacity int
	power        int
	fuelType     string
}

type LandVehicle struct {
	Vehicle
	torque int
}

type WaterVehicle struct {
	Vehicle
	kargoCapacity int
}

func (v *Vehicle) setFuelType(fuelType string) {
	v.fuelType = fuelType
}

func (v *Vehicle) getFuelType() string {
	return v.fuelType
}

func (lv *LandVehicle) setLandVehicle() {
	fmt.Println("Enter the fuel capacity:")
	fmt.Scanln(&lv.fuelCapacity)
	fmt.Println("Enter the power of the vehicle:")
	fmt.Scanln(&lv.power)
	fmt.Println("Enter the fuel type:")
	fmt.Scanln(&lv.fuelType)
	fmt.Println("Enter the max torque:")
	fmt.Scanln(&lv.torque)
}

func (lv *LandVehicle) maxSpeed() int {
	result := (lv.power * 735) / lv.torque
	return result
}

func (wv *WaterVehicle) maxSpeed(knots int) int {
	return knots * 1852 / 30
}

func main() {
	var car LandVehicle
	var bus LandVehicle
	ship := WaterVehicle{
		Vehicle: Vehicle{
			fuelCapacity: 30,
			power:        1000,
			fuelType:     "diesel",
		},
		kargoCapacity: 40000,
	}

	fmt.Println("Car details:")
	car.setLandVehicle()
	fmt.Println("Bus details:")
	bus.setLandVehicle()

	carMaxSpeed := car.maxSpeed()
	shipMaxSpeed := ship.maxSpeed(15)
	fmt.Println("Max speed of car:", carMaxSpeed)
	fmt.Println("Max speed of ship:", shipMaxSpeed)
}

