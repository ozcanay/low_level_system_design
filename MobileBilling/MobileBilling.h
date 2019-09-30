#ifndef MOBILEBILLING_MOBILEBILLING_H
#define MOBILEBILLING_MOBILEBILLING_H

#include <iostream>
#include <vector>
#include <unordered_set>
#include <typeinfo>

#include "PrepaidCustomer.h"
#include "PostpaidCustomer.h"

class MobileBilling {
    public:
        void addCustomer(Customer* customer);
        void deleteCustomer(Customer* customer);
        Customer* searchById(int id);
        Customer* searchByName(const std::string& name);
        std::vector<Customer*> searchByNumber(const std::vector<std::string>& phone_numbers);

        double getAveragePostpaidCallDuration(const PostpaidCustomer& postpaidCustomer);
        std::unordered_set<Customer*> queryPostpaidCustomers();
        double averagePostpaidBalance();

        double getAveragePrepaidCallDuration(const PrepaidCustomer& prepaidCustomer);
        std::unordered_set<Customer*> queryPrepaidCustomers();
        double averagePrepaidBalance();

        void displayPrepaidCustomers();
        void displayPostpaidCustomers();
        void displayCustomers();


    private:
        std::unordered_set<Customer*> prepaidCustomers_;
        std::unordered_set<Customer*> postpaidCustomers_;
        std::unordered_set<int> prepaidCustomerIds_;
        std::unordered_set<int> postpaidCustomerIds_;
        std::unordered_set<int> phoneNumbers_;
};


#endif //MOBILEBILLING_MOBILEBILLING_H
