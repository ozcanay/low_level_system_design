#ifndef MOBILEBILLING_MOBILEBILLING_H
#define MOBILEBILLING_MOBILEBILLING_H

#include <iostream>
#include <vector>
#include <unordered_set>

#include "PrepaidCustomer.h"
#include "PostpaidCustomer.h"

class MobileBilling {
    public:
        void addCustomer(Customer* customer);
        void deleteCustomer();
        Customer* searchById(int id);
        Customer* searchByName(const std::string& name);
        std::vector<Customer*> searchByNumber(const std::vector<std::string>& phone_numbers);

        double getAveragePostpaidCallDuration(const PostpaidCustomer& postpaidCustomer);
        std::vector<Customer*> queryPostpaidCustomers();
        double averagePostpaidBalance();

        double getAveragePrepaidCallDuration(const PrepaidCustomer& prepaidCustomer);
        std::vector<Customer*> queryPrepaidCustomers();
        double averagePrepaidBalance();

    private:
        std::vector<Customer*> prepaidCustomers_;
        std::vector<Customer*> postpaidCustomers_;
        std::unordered_set<int> prepaidCustomerIds_;
        std::unordered_set<int> postpaidCustomerIds_;
        std::unordered_set<int> phoneNumbers_;
};


#endif //MOBILEBILLING_MOBILEBILLING_H
