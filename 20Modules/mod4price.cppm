module mod4;

import :Order;
import <numeric>;

double Customer::sumPrice() const {
    return std::reduce(
        orders.begin(), orders.end(), double{},
        [](double running_total, const Order& order) {
            return running_total += order.m_price;
        }
    );
}

double Customer::averagePrice() const {
    if (orders.empty()) return double{};
    return sumPrice() / orders.size();
}
