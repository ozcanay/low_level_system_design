#include <iostream>

#include "ParkingLot.h"
#include "Car.h"
#include "Truck.h"
#include "Motorcycle.h"
#include "Bus.h"
#include "Minibus.h"

int main() {
    auto* parkingLot = new Building::ParkingLot(4);
    parkingLot->addParkingSpot(SpotSize::LARGE, 5);
    parkingLot->addParkingSpot(SpotSize::MEDIUM, 20);
    parkingLot->addParkingSpot(SpotSize::SMALL, 10);

    std::cout << parkingLot->getTotalSpots() << std::endl;
    parkingLot->printSpotInfo();

}