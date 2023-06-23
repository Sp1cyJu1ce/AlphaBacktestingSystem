#include "Backtester.h"
#include <iostream>

Backtester::Backtester(std::shared_ptr<Strategy> strategy, double initialCapital)
    : strategy(std::move(strategy)), initialCapital(initialCapital), portfolio(initialCapital) {}

void Backtester::loadData(const std::string& filename) {
    historicalData = loadStockData(filename);
}

void Backtester::run() {
    for (size_t i = 0; i < historicalData.size(); ++i) {
        StockData dayData = historicalData[i];
        Order order = strategy->generateOrder(historicalData, dayData, i);
        portfolio.processOrder(dayData, order);
        metrics.update(dayData, portfolio);
    }
}

void Backtester::printResults() const {
    metrics.print();
}