#ifndef MOBILEBILLING_MOBILEBILLING_H
#define MOBILEBILLING_MOBILEBILLING_H

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <tuple>
#include <typeinfo>
#include <map>

#include "PrepaidCustomer.h"
#include "PostpaidCustomer.h"

class MobileBilling {
    public:
        void addCustomer(Customer* customer);
        void deleteCustomer(Customer* customer);
        std::vector<Customer*> searchById(int id);
        std::vector<Customer*> searchByName(const std::string& name);
        Customer* searchByNumber(int phone_number);

        double getAveragePostpaidCallDuration();
        std::unordered_set<Customer*> queryPostpaidCustomers();
        double averagePostpaidBalance();

        double getAveragePrepaidCallDuration();
        std::unordered_set<Customer*> queryPrepaidCustomers();
        double averagePrepaidBalance();

        void displayPrepaidCustomers();
        void displayPostpaidCustomers();
        void displayCustomers();

    private:
        std::unordered_map< int, Customer* > phone_to_customer_map_{};
        std::unordered_map< int, Customer* > id_to_prepaidcustomer_map_{};
        std::unordered_map< int, Customer* > id_to_postpaidcustomer_map_{};
        std::multimap< std::string, Customer* > name_to_customer_map_{};

        std::unordered_set<Customer*> prepaidCustomers_;
        std::unordered_set<Customer*> postpaidCustomers_;
        std::unordered_set<int> prepaidCustomerIds_;
        std::unordered_set<int> postpaidCustomerIds_;
        std::unordered_set<int> phoneNumbers_;
};


#endif //MOBILEBILLING_MOBILEBILLING_H
