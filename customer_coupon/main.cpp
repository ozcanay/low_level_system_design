#include "Customer.h"

int main() {
    auto* customer1 = new Customer(1);
    auto* customer2 = new Customer(2);

    customer1->visitURL("www.amazon.com/123", 125);
    customer1->visitURL("www.amazon.com/123", 126);
    customer2->visitURL("www.amazon.com/349", 122);
    customer1->visitURL("www.amazon.com/714", 144);
    customer2->visitURL("www.amazon.com/666", 130);
    customer2->visitURL("www.amazon.com/236", 141);
    customer1->visitURL("www.amazon.com/897", 130);
    customer2->visitURL("www.amazon.com/666", 131);
    customer1->visitURL("www.amazon.com/714", 145);
    customer2->visitURL("www.amazon.com/610", 145);
    customer1->visitURL("www.amazon.com/111", 155);
    customer1->visitURL("www.amazon.com/111", 365);
    customer1->visitURL("www.amazon.com/111", 1);

    customer1->printVisitedURLs();
    customer2->printVisitedURLs();
    customer1->printCouponedURLs();
    customer2->printCouponedURLs();

    customer1->useCoupon("www.amazon.com/714");
    customer1->printCouponedURLs();

}