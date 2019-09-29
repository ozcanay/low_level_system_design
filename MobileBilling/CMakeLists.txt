cmake_minimum_required(VERSION 3.14)
project(MobileBilling)

set(CMAKE_CXX_STANDARD 17)

add_executable(MobileBilling main.cpp Customer.cpp PrepaidCustomer.cpp PostpaidCustomer.cpp MobileBilling.cpp)