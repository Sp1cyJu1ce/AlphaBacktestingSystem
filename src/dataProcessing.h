#ifndef DATA_PROCESSING_H
#define DATA_PROCESSING_H

#include <string>
#include <vector>

struct StockData {
    std::string date;
    double open, high, low, close, adjClose;
    int volume;
};

std::vector<StockData> loadStockData(const std::string& filename);

#endif