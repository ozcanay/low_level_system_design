//
// Created by ozcanay on 10/7/19.
//

#include "InterestAccount.h"

double InterestAccount::interest_rate_ = 0;

void InterestAccount::SetInterestRate(double interest_rate) {
    interest_rate_ = interest_rate;
}
