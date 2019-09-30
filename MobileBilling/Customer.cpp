#include "Customer.h"

double Customer::enquireBalance() {
    return balance_;
}

int Customer::getId() {
    return id_;
}

int Customer::getPhoneNumber() {
    return phone_number_;
}

std::string Customer::getName() {
    return name_;
}

double Customer::getCallDuration() {
    return call_duration_;
}

