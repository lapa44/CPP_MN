#include <iostream>
#include "task10_2.h"

double function10_2(double x) {
    return (1 / (2 * x + 3)) + 3 * x * x;
}

double prostokaty_10_2(double xp, double xk, int n, double eps, int counter) {
    double dx = (xk - xp) / (double)n;
    double rezultat = 0;
    for (int i=1; i<=n; i++) {
        counter++;
        rezultat += function10_2(xp + (double)i * dx);
    }
    if (rezultat * dx - 124.48 > eps) {
        return prostokaty_10_2(xp, xk, n*2, eps, counter);
    }
    std::cout << "Operations number in rectangles method: " << counter << "\n";
    return rezultat * dx;
}

double trapezy_10_2(double xp, double xk, int n, double eps, int counter) {
    double dx = (xk-xp) / (double)n;
    double rezultat = 0;
    for (int i=1; i<n; i++) {
        counter++;
        rezultat += function10_2(xp + (double)i * dx);
    }
    rezultat = (rezultat + (function10_2(xp) + function10_2(xk)) / 2) * dx;
    if (rezultat - 124.48 > eps) {
        return trapezy_10_2(xp, xk, n*2, eps, counter);
    }
    std::cout << "Operations number in trapezoidals method: " << counter << "\n";
    return rezultat;
}

void task10_2(double xp, double xk, double eps) {
    int n = 4; // initial number of intervals
    std::cout << "Result in rectangles method: " << prostokaty_10_2(xp, xk, n, eps, 0) << "\n\n";
    std::cout << "Result in trapezoidals method: "<< trapezy_10_2(xp, xk, n, eps, 0) << "\n\n";
}
