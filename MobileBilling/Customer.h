#ifndef MOBILEBILLING_CUSTOMER_H
#define MOBILEBILLING_CUSTOMER_H

#include <string>

class Customer {
    public:
        explicit Customer(int id);
        double enquireBalance();



    private:
        int id_;
        int phone_number_{};
        std::string name_{};
        double balance_;
        double call_duration_;
};


#endif //MOBILEBILLING_CUSTOMER_H
