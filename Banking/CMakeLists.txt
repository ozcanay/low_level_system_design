cmake_minimum_required(VERSION 3.14)
project(Banking)

set(CMAKE_CXX_STANDARD 17)

add_executable(Banking main.cpp BankAccount.h Bank.cpp Bank.h Transaction.cpp Transaction.h InterestAccount.cpp InterestAccount.h NonInterestAccount.cpp NonInterestAccount.h)