#ifndef STRATEGY_H
#define STRATEGY_H

#include "Order.h"
#include "dataProcessing.h"
#include <vector>

class Strategy {
public:
    virtual ~Strategy() = default;
    virtual Order generateOrder(const std::vector<StockData>& historicalData, const StockData& dayData, size_t dayIndex) = 0;
};

#endif