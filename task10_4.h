#ifndef CPP_MN_TASK10_4_H
#define CPP_MN_TASK10_4_H

#include <vector>

void task10_4(double xp, double xk, double h, const std::vector<double>& xVector, const std::vector<double>& yVector);

double lagrangeInterpolation(const std::vector<double>& xVector, const std::vector<double>& yVector, double x, int n);

#endif //CPP_MN_TASK10_4_H
