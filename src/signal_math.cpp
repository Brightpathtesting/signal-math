#include "signal_math.hpp"
#include <cmath>
#include <stdexcept>

namespace sm {

double rms(const std::vector<double>& x) {
    if (x.empty()) return 0.0;
    long double sum = 0.0;
    for (double v : x) sum += v * v;
    return std::sqrt(static_cast<double>(sum / x.size()));
}

std::vector<double> moving_average(const std::vector<double>& x, std::size_t window) {
    if (window == 0) throw std::invalid_argument("window must be > 0");
    if (x.empty()) return {};

    std::vector<double> out;
    out.reserve(x.size());

    long double acc = 0.0;
    for (std::size_t i = 0; i < x.size(); ++i) {
        acc += x[i];
        if (i >= window) acc -= x[i - window];
        std::size_t denom = (i + 1 < window) ? (i + 1) : window;
        out.push_back(static_cast<double>(acc / denom));
    }
    return out;
}

} // namespace sm
