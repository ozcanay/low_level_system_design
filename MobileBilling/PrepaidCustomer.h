#ifndef MOBILEBILLING_PREPAIDCUSTOMER_H
#define MOBILEBILLING_PREPAIDCUSTOMER_H

#include "Customer.h"

class PrepaidCustomer : public Customer {
    public:
        explicit PrepaidCustomer(int id) : Customer(id) {}
    private:

};


#endif //MOBILEBILLING_PREPAIDCUSTOMER_H
