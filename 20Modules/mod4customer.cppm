export module mod4:Customer;

import :Order; // Internal partition
import <vector>;
import <string>;

export class Customer {
private:
    std::string name;
    std::vector<Order> orders;
public:
    Customer(const std::string& n) : name{ n } {}
    void buy(const std::string& ordername, double price) {
        orders.push_back(Order{ 1, ordername, price });
    }
    void buy(int num, const std::string& ordername, double price) {
        orders.push_back(Order{ num, ordername, price });
    }
    double sumPrice() const;
    double averagePrice() const;
    void print() const;
};
