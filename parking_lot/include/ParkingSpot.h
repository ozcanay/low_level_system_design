#ifndef PARKING_LOT_PARKINGSPOT_H
#define PARKING_LOT_PARKINGSPOT_H

namespace Building {
    class ParkingSpot {
        public:
            explicit ParkingSpot(int w, int l) : width(w), length(l) {}

            inline int getArea() {
                return width * length;
            }

        private:
            int width;
            int length;
    };
}

#endif //PARKING_LOT_PARKINGSPOT_H
