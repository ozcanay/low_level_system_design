#include "ParkingLot.h"

namespace Building {
    void ParkingLot::addParkingSpot(Building::ParkingSpot spot, int count) {
        spotInfo.insert(spot, count);
    }
}


