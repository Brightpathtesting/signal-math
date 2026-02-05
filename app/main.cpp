#include "signal_math.hpp"
#include <iostream>

int main() {
    std::vector<double> x{1,2,3,4,5};
    std::cout << "rms=" << sm::rms(x) << "\n";
    auto ma = sm::moving_average(x, 3);
    std::cout << "ma3 last=" << ma.back() << "\n";
}
