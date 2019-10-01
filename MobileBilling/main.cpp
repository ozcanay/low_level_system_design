#include <iostream>
#include <memory>
#include <typeinfo>

#include "MobileBilling.h"

int main() {
    auto* mobileBilling = new MobileBilling;
    Customer* postPaidCustomer = new PostpaidCustomer(1, 123, "Aydin"); // UNIQUE PTR NEDEN CALISMADI? .GET() -> SEGFAULT VERDI
    // postPaidCustomer->call(10.3);
    Customer* prePaidCustomer  = new PrepaidCustomer(4, 126, "Gozde");
    postPaidCustomer->credit(10.7);
    std::cout << postPaidCustomer->enquireBalance() << std::endl;

    mobileBilling->addCustomer(prePaidCustomer);
    mobileBilling->addCustomer(postPaidCustomer);
    mobileBilling->displayCustomers();
    std::cout << mobileBilling->searchByNumber(123)->getName() << std::endl;
    mobileBilling->deleteCustomer(postPaidCustomer);
    mobileBilling->displayCustomers();
    mobileBilling->addCustomer(postPaidCustomer);

    Customer* prePaidCustomer2  = new PrepaidCustomer(2, 12123, "Gozde");
    mobileBilling->deleteCustomer(prePaidCustomer2);

    Customer* postPaidCustomer2 = new PostpaidCustomer(2, 100, "Ridvan");
    postPaidCustomer2->call(10.5);
    Customer* postPaidCustomer3 = new PostpaidCustomer(3, 200, "Emre");
    postPaidCustomer3->call(21.6);
    Customer* postPaidCustomer4 = new PostpaidCustomer(4, 300, "Hanife");
    postPaidCustomer4->call(11.8);
    Customer* postPaidCustomer5 = new PostpaidCustomer(5, 400, "Gozde");
    postPaidCustomer5->call(21.4);
    Customer* postPaidCustomer6 = new PostpaidCustomer(6, 500, "Refik");
    postPaidCustomer6->call(12.1);
    Customer* postPaidCustomer7 = new PostpaidCustomer(7, 600, "Arzu");
    postPaidCustomer7->call(4.0);

    mobileBilling->addCustomer(postPaidCustomer2);
    mobileBilling->addCustomer(postPaidCustomer3);
    mobileBilling->addCustomer(postPaidCustomer4);
    mobileBilling->addCustomer(postPaidCustomer5);
    mobileBilling->addCustomer(postPaidCustomer6);
    mobileBilling->addCustomer(postPaidCustomer7);

    for(auto i : mobileBilling->searchById(4)) {
        std::cout << i->getName() << std::endl;
    }

    for(auto i : mobileBilling->searchByName("Gozde")) {
        std::cout << i->getPhoneNumber() << std::endl;
    }

    std::cout << mobileBilling->getAveragePostpaidCallDuration() << std::endl;

    postPaidCustomer->call(1000);
    std::cout << postPaidCustomer->enquireBalance() << std::endl;


}