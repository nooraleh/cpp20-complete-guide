module; // start module unit with global module fragment


export module mod1; // module declaration, ends the global module fragment

import <string>;
import <vector>;

struct Order
{
public:
	Order(int c, const std::string& n, double p)
		: m_count{c}, m_name{n}, m_price{p}
	{ }

	int m_count;
	std::string m_name;
	double m_price;
};

export class Customer
{
public:
	Customer(const std::string& name)
		: m_name{name}
	{ }

	void buy(const std::string& order_name, double price)
	{
		// single item buy 
		m_orders.emplace_back(1, order_name, price);
	}

	void buy(int num, const std::string& order_name, double price)
	{
		// multiple item buy
		m_orders.emplace_back(num, order_name, price);
	}

	// declared functions, will be implemented in 'module implementation units'
	double sum_price() const;
	double average_price() const;
	void print() const;

private:
	std::string m_name;
	std::vector<Order> m_orders;
};