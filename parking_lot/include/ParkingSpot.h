#ifndef PARKING_LOT_PARKINGSPOT_H
#define PARKING_LOT_PARKINGSPOT_H

enum class SpotSize {
        SMALL,
        MEDIUM,
        LARGE
};

namespace Building {
    class ParkingSpot {
        public:
            explicit ParkingSpot(SpotSize size);
            SpotSize getSize();
            int getLevel() const;
            void setLevel(int level);
        private:
            SpotSize _size;
            int _level;
    };
}

#endif //PARKING_LOT_PARKINGSPOT_H
