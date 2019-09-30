#ifndef MOBILEBILLING_PREPAIDCUSTOMER_H
#define MOBILEBILLING_PREPAIDCUSTOMER_H

#include "Customer.h"

class PrepaidCustomer : public Customer {
    public:
        explicit PrepaidCustomer(int id, int phone_number, std::string name) : Customer(id, phone_number, std::move(name)) {}
        void credit(double amount) override;

    private:
        void recharge(double amount);

};


#endif //MOBILEBILLING_PREPAIDCUSTOMER_H
