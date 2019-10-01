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

void Customer::call(double duration) {
    if(balance_ - duration * 0.5 >= 0) {
        balance_ -= duration * 0.5;
    } else {
        duration = balance_ * 2;
        balance_ = 0;
        std::cout << "Balance is not sufficient for customer with phone number " << phone_number_
                << " to complete all of the call. " << "Only " << duration << " minutes of phone call "
                << "has been completed. Balance is now zero." << std::endl;
    }

    call_duration_ += duration;
}

