//
// Created by ozcanay on 9/29/19.
//

#include "PostpaidCustomer.h"

void PostpaidCustomer::billPay(double amount) {
    balance_ += amount;
}

void PostpaidCustomer::credit(double amount) {
    billPay(amount);
}
