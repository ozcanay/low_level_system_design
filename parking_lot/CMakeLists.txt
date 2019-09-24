cmake_minimum_required(VERSION 3.14)
project(parking_lot)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
        main.cpp
        src/Truck.cpp
        src/Bus.cpp
        src/Minibus.cpp
        src/Motorcycle.cpp
        src/Car.cpp
        src/ParkingLot.cpp)

add_executable(parking_lot ${SOURCES})

target_include_directories(parking_lot PRIVATE ${PROJECT_SOURCE_DIR}/include)