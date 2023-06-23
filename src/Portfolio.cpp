#include "Portfolio.h"

Portfolio::Portfolio(double initialCapital) : cash(initialCapital), numShares(0) {}

void Portfolio::processOrder(const StockData& data, const Order& order) {
    if (order.orderType == OrderType::BUY && cash >= data.close * order.quantity) {
        numShares += order.quantity;
        cash -= data.close * order.quantity;
    } else if (order.orderType == OrderType::SELL && numShares >= order.quantity) {
        numShares -= order.quantity;
        cash += data.close * order.quantity;
    }
}

double Portfolio::getPortfolioValue(const StockData& data) const {
    return cash + numShares * data.close;
}