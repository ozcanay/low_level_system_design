#pragma once

class Transaction {
    public:
        Transaction(unsigned int sender_id, unsigned int receiver_id, double amount) : sender_id_{sender_id},
                                                                                        receiver_id_{receiver_id},
                                                                                        amount_{amount} {};

    private:
        unsigned int sender_id_;
        unsigned int receiver_id_;
        double amount_;

};

