#pragma once
#include <vector>
#include <cstddef>

namespace sm {
double rms(const std::vector<double>& x);
std::vector<double> moving_average(const std::vector<double>& x, std::size_t window);
}
