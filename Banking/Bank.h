#pragma once

#include <vector>
#include <set>
#include <iostream>

#include "InterestAccount.h"
#include "NonInterestAccount.h"
#include "Transaction.h"

class Bank {
    public:
        void OpenBankAccount(BankAccount* account);
        void CloseBankAccount(BankAccount* account);
        BankAccount* InspectAccount(unsigned int id);

    private:
        std::vector<InterestAccount> interest_accounts_;
        std::vector<NonInterestAccount> non_interest_accounts_;
        std::set<Transaction> transactions_;
    public:

};

