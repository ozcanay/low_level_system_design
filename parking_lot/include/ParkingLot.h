#ifndef PARKING_LOT_PARKINGLOT_H
#define PARKING_LOT_PARKINGLOT_H

#include <unordered_map>
#include "ParkingSpot.h"

namespace Building {
    class ParkingLot {
        public:
            ParkingLot() = default;
            void addParkingSpot(ParkingSpot spot, int count);

        private:
            std::unordered_map<ParkingSpot, int> spotInfo;
    };
}

#endif //PARKING_LOT_PARKINGLOT_H
