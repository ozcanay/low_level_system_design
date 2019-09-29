#include <iostream>
#include <memory>

#include "MobileBilling.h"

int main() {
    auto* mobileBilling = new MobileBilling;
    mobileBilling->addCustomer(std::make_unique<PostpaidCustomer>(1, 123).get());
    mobileBilling->addCustomer(std::make_unique<PrepaidCustomer>(1, 124).get());
}