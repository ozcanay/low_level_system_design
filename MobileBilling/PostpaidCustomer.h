#ifndef MOBILEBILLING_POSTPAIDCUSTOMER_H
#define MOBILEBILLING_POSTPAIDCUSTOMER_H

#include "Customer.h"

class PostpaidCustomer : public Customer {
    public:
        explicit PostpaidCustomer(int id) : Customer(id) {}
    private:


};


#endif //MOBILEBILLING_POSTPAIDCUSTOMER_H
