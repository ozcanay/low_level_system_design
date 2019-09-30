#ifndef MOBILEBILLING_CUSTOMER_H
#define MOBILEBILLING_CUSTOMER_H

#include <string>

class Customer {
    public:
        explicit Customer(int id, int phone_number, std::string name) : id_(id), phone_number_(phone_number), name_(std::move(name)) {}
        double enquireBalance();
        virtual void credit(double amount) = 0;
        int getId();
        int getPhoneNumber();
        std::string getName();

    private:
        int id_;
        int phone_number_;
        std::string name_{"unknown name"};
        double call_duration_{0.0};
    protected:
        double balance_{0.0};
};


#endif //MOBILEBILLING_CUSTOMER_H
