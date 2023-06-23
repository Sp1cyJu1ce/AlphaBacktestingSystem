#include "Metrics.h"
#include <iostream>

Metrics::Metrics() {}

void Metrics::update(const StockData& data, const Portfolio& portfolio) {
    dailyPortfolioValue.push_back(portfolio.getPortfolioValue(data));
}

void Metrics::print() const {
    std::cout << "Daily Portfolio Value:" << std::endl;
    for (double value : dailyPortfolioValue) {
        std::cout << value << std::endl;
    }
}