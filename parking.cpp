#include <iostream>
#include <stack>
#include <string>

class ParkingSystem {
public:
    // Parking stack to simulate parking spots
    std::stack<std::string> parkingStack;
    int maxCapacity;

    // Constructor to set max capacity
    ParkingSystem(int capacity) {
        maxCapacity = capacity;
    }

    // Function to park a car
    bool parkCar(std::string carPlate) {
        if (parkingStack.size() < maxCapacity) {
            parkingStack.push(carPlate);
            std::cout << "Car parked: " << carPlate << std::endl;
            return true;
        } else {
            std::cout << "Parking lot full!" << std::endl;
            return false;
        }
    }

    // Function to remove a car
    bool removeCar() {
        if (!parkingStack.empty()) {
            std::string carPlate = parkingStack.top();
            parkingStack.pop();
            std::cout << "Car removed: " << carPlate << std::endl;
            return true;
        } else {
            std::cout << "No cars to remove!" << std::endl;
            return false;
        }
    }

    // Function to get the current number of parked cars
    int getCurrentParked() {
        return parkingStack.size();
    }
};

int main() {
    ParkingSystem system(5); // Set parking capacity to 5
    system.parkCar("ABC123");
    system.parkCar("XYZ456");
    system.removeCar();
    return 0;
}
