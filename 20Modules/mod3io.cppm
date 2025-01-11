module mod3;

import :Order;
import <print>;

void Customer::print() const
{
    for (const auto& order : m_orders)
    {
        std::println("{}", order);
    }

    // print sum
    std::println("{:25} ------", ' ');
    std::println("{:25} {:6.2f}", " Sum:", sum_price());
}