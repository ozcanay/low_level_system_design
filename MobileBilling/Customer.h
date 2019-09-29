#ifndef MOBILEBILLING_CUSTOMER_H
#define MOBILEBILLING_CUSTOMER_H

#include <string>

class Customer {
    public:
        explicit Customer(int id, int phone_number) : id_(id), phone_number_(phone_number) {}
        double enquireBalance();
        virtual void credit(double amount) = 0;
        int getId();
        int getPhoneNumber();

    private:
        int id_;
        int phone_number_;
        std::string name_{};
        double call_duration_{};
    protected:
        double balance_{};
};


#endif //MOBILEBILLING_CUSTOMER_H
