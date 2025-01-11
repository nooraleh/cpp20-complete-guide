module mod3;

import :Order;
import <numeric>;

double Customer::sum_price() const
{
	return std::reduce(
		m_orders.begin(), m_orders.end(), double{},
		[](double running_total, const Order& order)
		{
			return running_total += order.m_price;
		}
	);
}


double Customer::average_price() const
{
	if (m_orders.empty()) { return double{}; }

	return sum_price() / m_orders.size();
}