#include "PrepaidCustomer.h"

void PrepaidCustomer::recharge(double amount) {
    balance_ += amount;
}

void PrepaidCustomer::credit(double amount) {
    recharge(amount);
}

