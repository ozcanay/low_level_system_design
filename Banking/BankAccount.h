#pragma once

class BankAccount {
    public:
        explicit BankAccount(unsigned int id) : id_{id}, balance_{0} {};
        virtual double GetBalance() const = 0;
        virtual void DepositMoney(double amount) = 0;
        virtual bool WithdrawMoney(double amount) = 0;
        virtual bool SendMoney(unsigned int id, double amount) = 0;
        virtual void ReceiveMoney(double amount) = 0;
        virtual void PrintRecentTransactions() = 0;

    protected:
        double balance_;

    private:
        const unsigned int id_;


};

