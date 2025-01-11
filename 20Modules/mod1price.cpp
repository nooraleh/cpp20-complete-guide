module mod1; // implementation unit of module Mod1

import <numeric>;

double Customer::sum_price() const
{
	return std::reduce(
		m_orders.begin(), m_orders.end(),
		double{},
		[](double sum_total, const Order& order)
		{
			return sum_total + order.m_price;
		}
	);
}

double Customer::average_price() const
{
	if (m_orders.empty()) { return double{ }; }

	return sum_price() / m_orders.size();
}