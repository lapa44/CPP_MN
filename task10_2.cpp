#include <iostream>
#include "task10_2.h"

double function10_2(double x) {
    return (1 / (2 * x + 3)) + 3 * x * x;
}

double rectangles_10_2(double xp, double xk, int n, double eps, int counter) {
    double dx = (xk - xp) / (double)n;
    double result = 0;
    for (int i=1; i<=n; i++) {
        counter++;
        result += function10_2(xp + (double)i * dx);
    }
    if (result * dx - 124.48 > eps) {
        return rectangles_10_2(xp, xk, n * 2, eps, counter);
    }
    std::cout << "Operations number in rectangles method: " << counter << "\n";
    return result * dx;
}

double trapezoidals_10_2(double xp, double xk, int n, double eps, int counter) {
    double dx = (xk-xp) / (double)n;
    double result = 0;
    for (int i=1; i<n; i++) {
        counter++;
        result += function10_2(xp + (double)i * dx);
    }
    result = (result + (function10_2(xp) + function10_2(xk)) / 2) * dx;
    if (result - 124.48 > eps) {
        return trapezoidals_10_2(xp, xk, n * 2, eps, counter);
    }
    std::cout << "Operations number in trapezoidals method: " << counter << "\n";
    return result;
}

void task10_2(double xp, double xk, double eps) {
    int n = 4; // initial number of intervals
    std::cout << "Result in rectangles method: " << rectangles_10_2(xp, xk, n, eps, 0) << "\n\n";
    std::cout << "Result in trapezoidals method: " << trapezoidals_10_2(xp, xk, n, eps, 0) << "\n\n";
}
