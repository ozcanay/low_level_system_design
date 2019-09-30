#include <iostream>
#include <memory>
#include <typeinfo>

#include "MobileBilling.h"

int main() {
    auto* mobileBilling = new MobileBilling;
    Customer* postPaidCustomer = new PostpaidCustomer(1, 123, "Aydin"); // UNIQUE PTR NEDEN CALISMADI? .GET() -> SEGFAULT VERDI
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
}