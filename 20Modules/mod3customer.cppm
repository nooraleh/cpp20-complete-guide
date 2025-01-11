export module mod3:Customer; // interface partition declaration


import <vector>;
import <string>;

import :Order; // import internal partition to use Order


export class Customer {
private:
	std::string m_name;
	std::vector<Order> m_orders;
public:
	Customer(const std::string& n)
		: m_name{ n } {
	}
	void buy(const std::string& ordername, double price) {
		m_orders.emplace_back( 1, ordername, price );
	}
	void buy(int num, const std::string& ordername, double price) {
		m_orders.emplace_back( num, ordername, price );
	}
	double sum_price() const;
	double average_price() const;
	void print() const;
};
