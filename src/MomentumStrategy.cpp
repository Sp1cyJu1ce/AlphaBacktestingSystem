#include "MomentumStrategy.h"

MomentumStrategy::MomentumStrategy(int lookbackPeriod) : lookbackPeriod(lookbackPeriod) {}

Order MomentumStrategy::generateOrder(const std::vector<StockData>& historicalData, const StockData& dayData, size_t dayIndex) {
    if (dayIndex < lookbackPeriod) {
        // Not enough data to make a decision
        return Order{0, OrderType::HOLD};
    }
    
    double currentPrice = dayData.close;
    double priceNdaysAgo = historicalData[dayIndex - lookbackPeriod].close;

    if (currentPrice > priceNdaysAgo) {
        // Price has gone up, buy the stock
        return Order{1, OrderType::BUY};
    } else if (currentPrice < priceNdaysAgo) {
        // Price has gone down, sell the stock
        return Order{-1, OrderType::SELL};
    } else {
        // Price has not changed, hold
        return Order{0, OrderType::HOLD};
    }
}