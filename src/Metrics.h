#ifndef METRICS_H
#define METRICS_H

#include "Portfolio.h"
#include <vector>

class Metrics {
public:
    Metrics();

    void update(const StockData& data, const Portfolio& portfolio);
    void print() const;

private:
    std::vector<double> dailyPortfolioValue;
};

#endif