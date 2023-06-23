#ifndef PORTFOLIO_H
#define PORTFOLIO_H

#include "Order.h"
#include "dataProcessing.h"

class Portfolio {
public:
    explicit Portfolio(double initialCapital);
    void processOrder(const StockData& data, const Order& order);
    double getPortfolioValue(const StockData& data) const;

private:
    double cash;
    int numShares;
};

#endif