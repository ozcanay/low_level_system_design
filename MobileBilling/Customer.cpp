#include "Customer.h"

double Customer::enquireBalance() {
    return balance;
}

Customer::Customer(int id) {
    id_ = id;
}
