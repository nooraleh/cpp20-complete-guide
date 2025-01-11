module mod4;

import :Order;
import <print>;

void Customer::print() const {
    for (const auto& order : orders) {
        std::println("{}", order);
    }

    std::println("{:25} ------", ' ');
    std::println("{:25} {:6.2f}", " Sum:", sumPrice());
}
