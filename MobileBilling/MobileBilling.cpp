#include "MobileBilling.h"

std::unordered_set<Customer*> MobileBilling::queryPostpaidCustomers() {
    return postpaidCustomers_;
}

std::unordered_set<Customer*> MobileBilling::queryPrepaidCustomers() {
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
        prepaidCustomers_.insert(customer);
        prepaidCustomerIds_.insert(customer->getId());
    } else if(typeid(PostpaidCustomer) == typeid(*customer)) {
        std::cout << "Postpaid customer is being added to the mobile billing with an ID of " << customer->getId() << " and a phone number of " << customer->getPhoneNumber() << "."  << std::endl;
        postpaidCustomers_.insert(customer);
        postpaidCustomerIds_.insert(customer->getId());
    }

    phoneNumbers_.insert(customer->getPhoneNumber());
}

void MobileBilling::deleteCustomer(Customer* customer) {
    if(typeid(PrepaidCustomer) == typeid(*customer)) {
        std::cout << "Prepaid customer is being deleted from the mobile billing with an ID of " << customer->getId() << " and a phone number of " << customer->getPhoneNumber() << "."  << std::endl;
        prepaidCustomers_.erase(customer);
        prepaidCustomerIds_.erase(customer->getId());
    } else if(typeid(PostpaidCustomer) == typeid(*customer)) {
        std::cout << "Postpaid customer is being deleted from the mobile billing with an ID of " << customer->getId() << " and a phone number of " << customer->getPhoneNumber() << "."  << std::endl;
        postpaidCustomers_.erase(customer);
        postpaidCustomerIds_.erase(customer->getId());
    }
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

void MobileBilling::displayPrepaidCustomers() {
    std::cout << "Prepaid Customer Info: " << std::endl;
    std::cout << "-----------------------" << std::endl << std::endl;

    for(auto prepaidCustomer : prepaidCustomers_) {
        std::cout << prepaidCustomer->getId() << " " << prepaidCustomer->getPhoneNumber() << std::endl;
    }

    std::cout << std::endl;
}

void MobileBilling::displayPostpaidCustomers() {
    std::cout << "Postpaid Customer Info: " << std::endl;
    std::cout << "-----------------------" << std::endl << std::endl;

    for(auto postpaidCustomer : postpaidCustomers_) {
        std::cout << postpaidCustomer->getId() << " " << postpaidCustomer->getPhoneNumber() << std::endl;
    }

    std::cout << std::endl;
}

void MobileBilling::displayCustomers() {
    displayPostpaidCustomers();
    displayPrepaidCustomers();
}
