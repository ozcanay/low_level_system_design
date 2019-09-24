#ifndef CUSTOMER_COUPON_CUSTOMER_H
#define CUSTOMER_COUPON_CUSTOMER_H

#include <iostream>
#include <string>
#include <map>
#include <unordered_set>

class Customer {
    public:
        explicit Customer(int cid) : customer_id(cid) {}
        void visitURL(const std::string& url, int date);
        bool wonCoupon(const std::string& url, int date);
        void printVisitedURLs();
        void printCouponedURLs();
        void useCoupon(const std::string& date);

    private:
        int customer_id;
        std::multimap<std::string, int> visitedURLInfo;
        std::unordered_set<std::string> visitedURLs;
        std::unordered_set<std::string> couponedURLs;
};

#endif //CUSTOMER_COUPON_CUSTOMER_H
