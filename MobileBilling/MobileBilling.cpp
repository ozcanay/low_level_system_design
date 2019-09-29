//
// Created by ozcanay on 9/29/19.
//

#include "MobileBilling.h"

std::vector<PostpaidCustomer *> MobileBilling::queryPostpaidCustomers() {
    return postpaidCustomers_;
}

std::vector<PrepaidCustomer *> MobileBilling::queryPrepaidCustomers() {
    return prepaidCustomers_;
}
