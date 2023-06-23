#include "Backtester.h"
#include "MomentumStrategy.h"
#include <memory>

int main() {
    std::shared_ptr<Strategy> strategy = std::make_shared<MomentumStrategy>(10);
    Backtester backtester(strategy, 10000.0);

    backtester.loadData("../data/NKLA.csv");
    backtester.run();
    backtester.printResults();

    return 0;
}