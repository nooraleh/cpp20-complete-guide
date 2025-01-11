module mod4:Order;

import <string>;
import <format>;

struct Order {
    int m_count;
    std::string m_name;
    double m_price;

    Order(int count, std::string name, double price)
        : m_count{ count }, m_name{ name }, m_price{ price } {
    }
};

template<>
struct std::formatter<Order> {
    template<class ParseContext>
    constexpr ParseContext::iterator parse(ParseContext& ctx) {
        return ctx.begin();
    }

    template<class FmtContext>
    FmtContext::iterator format(const Order& order, FmtContext& ctx) const {
        return std::format_to(
            ctx.out(),
            "{:3} {:14} {:6.2f} {:6.2f}",
            order.m_count, order.m_name, order.m_price, order.m_count * order.m_price
        );
    }
};
