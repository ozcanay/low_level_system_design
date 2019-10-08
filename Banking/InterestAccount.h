#pragma once

#include "BankAccount.h"


class InterestAccount : public BankAccount {
    public:
        void SetInterestRate(double interest_rate);
        double GetBalanceAfterTime(double time);

    private:
        static double interest_rate_;

};

