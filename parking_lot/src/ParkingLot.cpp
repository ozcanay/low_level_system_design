#include <iostream>
#include "ParkingLot.h"

namespace Building {
    ParkingLot::ParkingLot(int level) {
        _level = level;
    }

    void ParkingLot::addParkingSpot(SpotSize size, int count) {
        for(int i = 0; i < _level; ++i) {
            for(int j = 0; j < count; ++j) {
                auto* parking_spot = new ParkingSpot(size);
                parking_spot->setLevel(i);

                parkingSpots.insert(parking_spot);
            }
        }
    }

    void ParkingLot::removeParkingSpot(SpotSize size, int count) {
        for(int i = 0; i < _level; ++i) {
            int _count = count;
            for(auto it = parkingSpots.begin(); it != parkingSpots.end() && _count; ++it) {
                if((*it)->getSize() == size && (*it)->getLevel() == i) {
                    parkingSpots.erase(it);
                    --_count;
                }
            }
        }
    }

    int ParkingLot::getTotalSpots() const {
        return parkingSpots.size();
    }

    void ParkingLot::printSpotInfo() const {
        std::string size;

        for(const auto parkingSpot : parkingSpots) {
            switch(parkingSpot->getSize()) {
                case SpotSize::SMALL:
                    size = "Small";
                    break;
                case SpotSize::MEDIUM:
                    size = "Medium";
                    break;
                case SpotSize::LARGE:
                    size = "Large";
                    break;
                default:
                    break;
            }

            std::cout << size << " " << parkingSpot->getLevel() << std::endl;
        }
    }
}


