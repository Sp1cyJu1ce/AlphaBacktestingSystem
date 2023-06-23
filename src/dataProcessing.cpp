#include "dataProcessing.h"
#include <fstream>
#include <sstream>

std::vector<StockData> loadStockData(const std::string& filename) {
    std::vector<StockData> stockDataList;

    std::ifstream file(filename);
    std::string line;
    getline(file, line);  // Skip header line

    while (getline(file, line)) {
        std::istringstream ss(line);
        StockData data;
        std::string value;

        getline(ss, value, '\t'); data.date = value;
        getline(ss, value, '\t'); data.open = std::stod(value);
        getline(ss, value, '\t'); data.high = std::stod(value);
        getline(ss, value, '\t'); data.low = std::stod(value);
        getline(ss, value, '\t'); data.close = std::stod(value);
        getline(ss, value, '\t'); data.adjClose = std::stod(value);
        getline(ss, value, '\t'); data.volume = std::stoi(value);

        stockDataList.push_back(data);
    }

    return stockDataList;
}