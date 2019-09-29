//
// Created by ozcanay on 9/29/19.
//

#include "MobileBilling.h"

std::vector<Customer*> MobileBilling::queryPostpaidCustomers() {
    return postpaidCustomers_;
}

std::vector<Customer*> MobileBilling::queryPrepaidCustomers() {
    return prepaidCustomers_;
}

double MobileBilling::averagePostpaidBalance() {
    double sum = 0.0;

    for(auto postpaidCustomer : postpaidCustomers_) {
        sum += postpaidCustomer->enquireBalance();
    }

    return sum / postpaidCustomers_.size();
}

void MobileBilling::addCustomer(Customer* customer) {
    if(typeid(PrepaidCustomer) == typeid(*customer)) {
        std::cout << "Prepaid customer is being added to the mobile billing with an ID of " << customer->getId() << " and a phone number of " << customer->getPhoneNumber() << "."  << std::endl;
        prepaidCustomers_.push_back(customer);
    } else if(typeid(PostpaidCustomer) == typeid(*customer)) {
        std::cout << "Postpaid customer is being added to the mobile billing." << std::endl;
        postpaidCustomers_.push_back(customer);
    }
}

void MobileBilling::deleteCustomer() {

}

Customer *MobileBilling::searchById(int id) {
    Customer* result{};

    if(postpaidCustomerIds_.find(id) != postpaidCustomerIds_.end()) {
        for(auto postpaidCustomer : postpaidCustomers_) {
            if(postpaidCustomer->getId() == id)
                result = postpaidCustomer;
        }
    } else if(prepaidCustomerIds_.find(id) != prepaidCustomerIds_.end()) {
        for(auto prepaidCustomer : prepaidCustomers_) {
            if(prepaidCustomer->getId() == id)
                result = prepaidCustomer;
        }
    }

    return result;
}

Customer *MobileBilling::searchByName(const std::string &name) {
    return nullptr;
}

std::vector<Customer *> MobileBilling::searchByNumber(const std::vector<std::string>& phone_numbers) {
    return std::vector<Customer *>();
}

double MobileBilling::getAveragePostpaidCallDuration(const PostpaidCustomer &postpaidCustomer) {
    return 0;
}

double MobileBilling::getAveragePrepaidCallDuration(const PrepaidCustomer &prepaidCustomer) {
    return 0;
}

double MobileBilling::averagePrepaidBalance() {
    return 0;
}
