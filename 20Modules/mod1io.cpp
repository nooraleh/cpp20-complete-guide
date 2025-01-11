module mod1;

import <format>;
import <iostream>;
import <print>;

template<>
struct std::formatter<Order>
{
    template<class ParseContext>
    constexpr ParseContext::iterator parse(ParseContext& ctx)
    {
        return ctx.begin();
    }

    template<class FmtContext>
    FmtContext::iterator format(Order order, FmtContext& ctx) const
    {
        return std::format_to(
            ctx.out(),
            "{:3} {:14} {:6.2f} {:6.2f}",
            order.m_count, order.m_name, order.m_price, order.m_count * order.m_price
            );
    }
};

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