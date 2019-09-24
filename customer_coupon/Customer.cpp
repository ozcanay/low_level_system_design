#include "Customer.h"

bool Customer::wonCoupon(const std::string &url, int date) {
    date %= 365;
    auto range = visitedURLInfo.equal_range(url);

    for(auto it = range.first; it != range.second; ++it) {
        if(it->second + 1 == date)
            return true;
    }

    return false;
}

void Customer::visitURL(const std::string &url, int date) {
    date %= 365;
    visitedURLs.insert(url);
    visitedURLInfo.insert({url, date});

    if(wonCoupon(url, date)) {
        std::cout << "Customer " << customer_id <<  " won coupon for " << url << " at date " << date << "." << std::endl;
        couponedURLs.insert(url);
    }
}

void Customer::printVisitedURLs() {
    std::cout << "Customer with the ID number " << customer_id << " has visited following URL(s): ";

    for(const auto& visitedURL : visitedURLs) {
        std::cout << visitedURL << ", ";
    }

    std::cout << std::endl;
}

void Customer::printCouponedURLs() {
    std::cout << "Customer with the ID number " << customer_id << " has coupon(s) for the following URL(s): ";

    for(const auto& visitedURL : couponedURLs) {
        std::cout << visitedURL << ", ";
    }

    std::cout << std::endl;
}

void Customer::useCoupon(const std::string &url) {
    couponedURLs.erase(url);
}

