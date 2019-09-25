#ifndef PARKING_LOT_PARKINGLOT_H
#define PARKING_LOT_PARKINGLOT_H

#include <unordered_map>
#include <unordered_set>
#include "ParkingSpot.h"

namespace Building {
    class ParkingLot {
        public:
            explicit ParkingLot(int level);
            void addParkingSpot(SpotSize size, int count);
            void removeParkingSpot(SpotSize size, int count);
            int getTotalSpots() const;
            void printSpotInfo() const;

        private:
            int _level{0};
            std::unordered_set<Building::ParkingSpot*> parkingSpots{};
    };
}

#endif //PARKING_LOT_PARKINGLOT_H
