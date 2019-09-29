#ifndef MOBILEBILLING_POSTPAIDCUSTOMER_H
#define MOBILEBILLING_POSTPAIDCUSTOMER_H

#include "Customer.h"

class PostpaidCustomer : public Customer {
    public:
        explicit PostpaidCustomer(int id, int phone_number) : Customer(id, phone_number) {}
        void credit(double amount) override;
    private:
        void billPay();


};

#endif //MOBILEBILLING_POSTPAIDCUSTOMER_H


