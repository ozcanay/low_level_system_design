#ifndef MOBILEBILLING_POSTPAIDCUSTOMER_H
#define MOBILEBILLING_POSTPAIDCUSTOMER_H

#include "Customer.h"

class PostpaidCustomer : public Customer {
    public:
        explicit PostpaidCustomer(int id, int phone_number, std::string name) : Customer(id, phone_number, std::move(name)) {}
        void credit(double amount) override;
    private:
        void billPay(double amount);

};

#endif //MOBILEBILLING_POSTPAIDCUSTOMER_H


