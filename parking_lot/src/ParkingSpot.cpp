#include "ParkingSpot.h"

namespace Building {
    ParkingSpot::ParkingSpot(SpotSize size) {
        _size = size;
    }

    SpotSize ParkingSpot::getSize() {
        return _size;
    }

    int ParkingSpot::getLevel() const {
        return _level;
    }

    void ParkingSpot::setLevel(int level) {
        _level = level;
    }
}


