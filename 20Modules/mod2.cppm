export module mod2;	// module declaration


import <vector>;
import :Order;		// import internal partition 'Order'

export class Customer
{
public:
	Customer(const std::string& name)
		: m_name{name}
	{ }

	void buy(const std::string order_name, double price)
	{
		m_orders.emplace_back(1, order_name, price);
	}

	void buy(int num, const std::string& order_name, double price)
	{
		m_orders.emplace_back(num, order_name, price);
	}

	double sum_price() const;
	double average_price() const;
	void print() const;
private:
	std::string m_name;
	std::vector<Order> m_orders;
};