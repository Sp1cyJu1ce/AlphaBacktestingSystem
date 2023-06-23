#ifndef ORDER_H
#define ORDER_H

enum class OrderType { BUY, SELL, HOLD };

struct Order {
    int quantity;
    OrderType orderType;
};

#endif