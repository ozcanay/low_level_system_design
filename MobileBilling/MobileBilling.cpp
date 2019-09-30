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
        if(phone_to_customer_map_.find(customer->getPhoneNumber()) == phone_to_customer_map_.end() && id_to_prepaidcustomer_map_.find(customer->getId()) == id_to_prepaidcustomer_map_.end()) {
            std::cout << "Prepaid customer is being added to the mobile billing with an ID of " << customer->getId() << " and a phone number of " << customer->getPhoneNumber() << "."  << std::endl;
            prepaidCustomers_.insert(customer);
            prepaidCustomerIds_.insert(customer->getId());
            id_to_prepaidcustomer_map_.insert({customer->getId(), customer});
        } else {
            std::cout << "Prepaid customer with the same phone or with the same id number already exists in the system. Customer not added to the system." << std::endl;
        }

    } else if(typeid(PostpaidCustomer) == typeid(*customer)) {
        if(phone_to_customer_map_.find(customer->getPhoneNumber()) == phone_to_customer_map_.end() && id_to_postpaidcustomer_map_.find(customer->getId()) == id_to_postpaidcustomer_map_.end()) {
            std::cout << "Postpaid customer is being added to the mobile billing with an ID of " << customer->getId() << " and a phone number of " << customer->getPhoneNumber() << "." << std::endl;
            postpaidCustomers_.insert(customer);
            postpaidCustomerIds_.insert(customer->getId());
            id_to_postpaidcustomer_map_.insert({customer->getId(), customer});
        } else {
            std::cout << "Postpaid customer with the same phone or with the same id number already exists in the system. Customer not added to the system." << std::endl;
        }
    }

    phoneNumbers_.insert(customer->getPhoneNumber());

    phone_to_customer_map_[customer->getPhoneNumber()] = customer;
    name_to_customer_map_.insert({customer->getName(), customer});
}

void MobileBilling::deleteCustomer(Customer* customer) {
    if(phone_to_customer_map_.find(customer->getPhoneNumber()) != phone_to_customer_map_.end()) {
        if (typeid(PrepaidCustomer) == typeid(*customer)) {
            std::cout << "Prepaid customer is being deleted from the mobile billing with an ID of "
                      << customer->getId() << " and a phone number of " << customer->getPhoneNumber() << "."
                      << std::endl;
            prepaidCustomers_.erase(customer);
            prepaidCustomerIds_.erase(customer->getId());
        } else if (typeid(PostpaidCustomer) == typeid(*customer)) {
            std::cout << "Postpaid customer is being deleted from the mobile billing with an ID of "
                      << customer->getId() << " and a phone number of " << customer->getPhoneNumber() << "."
                      << std::endl;
            postpaidCustomers_.erase(customer);
            postpaidCustomerIds_.erase(customer->getId());
        }
    } else {
        std::cout << "Cannot delete, customer does not exist in the system." << std::endl;
    }
}

std::vector<Customer*> MobileBilling::searchById(int id) {
/*    if(id_to_customer_map_.find(id) != id_to_customer_map_.end()) {

    }*/
    return {};
}

std::vector<Customer*> MobileBilling::searchByName(const std::string& name) {
    return {};
}

Customer* MobileBilling::searchByNumber(int phone_number) {
    Customer* result{};
    auto it = phone_to_customer_map_.find(phone_number);

    if(it != phone_to_customer_map_.end())
        result = it->second;

    return result;
}

double MobileBilling::getAveragePostpaidCallDuration() {
    double sum{0.0};

    for(auto postpaidCustomer : postpaidCustomers_) {
        sum += postpaidCustomer->getCallDuration();
    }

    return sum / postpaidCustomers_.size();
}

double MobileBilling::getAveragePrepaidCallDuration() {
    double sum{0.0};

    for(auto prepaidCustomer : prepaidCustomers_) {
        sum += prepaidCustomer->getCallDuration();
    }

    return sum / prepaidCustomers_.size();
}

double MobileBilling::averagePrepaidBalance() {
    return 0;
}

void MobileBilling::displayPrepaidCustomers() {
    std::cout << "Prepaid Customer Info: " << std::endl;
    std::cout << "-----------------------" << std::endl;
    std::cout << "id   phone number" << std::endl;

    for(auto prepaidCustomer : prepaidCustomers_) {
        std::cout << prepaidCustomer->getId() << " " << prepaidCustomer->getPhoneNumber() << std::endl;
    }

    std::cout << std::endl;
}

void MobileBilling::displayPostpaidCustomers() {
    std::cout << "Postpaid Customer Info: " << std::endl;
    std::cout << "-----------------------" << std::endl;
    std::cout << "id   phone number" << std::endl;

    for(auto postpaidCustomer : postpaidCustomers_) {
        std::cout << postpaidCustomer->getId() << " " << postpaidCustomer->getPhoneNumber() << std::endl;
    }

    std::cout << std::endl;
}

void MobileBilling::displayCustomers() {
    displayPostpaidCustomers();
    displayPrepaidCustomers();
}
