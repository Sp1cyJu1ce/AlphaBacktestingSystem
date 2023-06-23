#ifndef MOMENTUM_STRATEGY_H
#define MOMENTUM_STRATEGY_H

#include "Strategy.h"

class MomentumStrategy : public Strategy {
public:
    explicit MomentumStrategy(int lookbackPeriod);

    Order generateOrder(const std::vector<StockData>& historicalData, const StockData& dayData, size_t dayIndex) override;

private:
    int lookbackPeriod;
};

#endif