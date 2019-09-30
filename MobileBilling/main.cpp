#include <iostream>
#include <memory>
#include <typeinfo>

#include "MobileBilling.h"

int main() {
    auto* mobileBilling = new MobileBilling;
    Customer* postPaidCustomer = new PostpaidCustomer(1, 123);
    Customer* prePaidCustomer  = new PrepaidCustomer(4, 126);

    mobileBilling->addCustomer(prePaidCustomer);
    mobileBilling->addCustomer(postPaidCustomer);
    mobileBilling->displayCustomers();
    std::cout << mobileBilling->searchById(1)->getPhoneNumber();
    mobileBilling->deleteCustomer(postPaidCustomer);
    mobileBilling->displayCustomers();
}