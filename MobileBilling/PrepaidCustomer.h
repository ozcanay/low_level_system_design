#ifndef MOBILEBILLING_PREPAIDCUSTOMER_H
#define MOBILEBILLING_PREPAIDCUSTOMER_H

#include "Customer.h"

class PrepaidCustomer : public Customer {
    public:
        explicit PrepaidCustomer(int id, int phone_number) : Customer(id, phone_number) {}
        void credit(double amount) override {
            recharge(amount);
        }

    private:
        void recharge(double amount) {
            balance_ += amount;
        }

};


#endif //MOBILEBILLING_PREPAIDCUSTOMER_H
