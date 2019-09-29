#ifndef MOBILEBILLING_MOBILEBILLING_H
#define MOBILEBILLING_MOBILEBILLING_H

#include <vector>
#include "PrepaidCustomer.h"
#include "PostpaidCustomer.h"

class MobileBilling {
    public:
        void addCustomer(const Customer& customer);
        void deleteCustomer();
        Customer* searchById(int id);
        Customer* searchByName(const std::string& name);
        std::vector<Customer*> searchByNumber(const std::vector<std::string> phone_numbers);

        double getAveragePostpaidCallDuration(const PostpaidCustomer& postpaidCustomer);
        std::vector<PostpaidCustomer*> queryPostpaidCustomers();
        double averagePostpaidBalance();

        double getAveragePrepaidCallDuration(const PrepaidCustomer& prepaidCustomer);
        std::vector<PrepaidCustomer*> queryPrepaidCustomers();
        double averagePrepaidBalance();

    private:
        std::vector<PrepaidCustomer*> prepaidCustomers_;
        std::vector<PostpaidCustomer*> postpaidCustomers_;

};


#endif //MOBILEBILLING_MOBILEBILLING_H
