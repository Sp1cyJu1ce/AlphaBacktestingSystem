#ifndef BACKTESTER_H
#define BACKTESTER_H

#include "Strategy.h"
#include "Portfolio.h"
#include "Metrics.h"
#include "dataProcessing.h"
#include <memory>
#include <vector>

class Backtester {
public:
    Backtester(std::shared_ptr<Strategy> strategy, double initialCapital);

    void loadData(const std::string& filename);
    void run();
    void printResults() const;

private:
    std::vector<StockData> historicalData;
    std::shared_ptr<Strategy> strategy;
    Portfolio portfolio;
    Metrics metrics;
    double initialCapital;
};

#endif