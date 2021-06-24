#include <cmath>
#include "task10_1.h"
#include <iostream>

double function10_1(double x) {
    return 3 * cos(0.5 * x) - exp(x) + 1;
}

double derivative10_1(double x) {
    return -exp(x) - 1.5 * sin(0.5 * x);
}

double task10_1a(double xp, double xk, double eps, double incrementer, int counter) {
    double result;
    for (double i=-3; i<=2; i += incrementer) {
        counter++;
        result = function10_1(i);
        //std::cout << "Estimation no. " << counter << "=\t"  << result << "for x = " << i << "\n";
        if (result == 0 || std::abs(result) < eps) {
            std::cout << "Number of operations in 100064's method: " << counter << "\n";
            return i;
        }
    }
    return task10_1a(xp, xk, eps, incrementer/6, counter);
}

double task10_1b(double x, double eps) {

    double f0 = function10_1(x), x0 = x;
    int counter = 1;

    while (fabs(f0) > eps) {
        x = x0;
        x0 = x - f0 / derivative10_1(x);
        f0 = function10_1(x0);
        std::cout << "Estimated " << f0 << " for x = " << x0 << "\n";
        counter++;
    }
    std::cout << "\nNumber of operations in Newton's method: " << counter << std::endl;
    return x0;
}

void task10_1(double xp, double xk, double eps, double incrementer) {
    std::cout << "100064's method result: " << task10_1a(xp, xk, eps, incrementer) << "\n\n";
    std::cout << "Newton's Method result: " << task10_1b(2, eps) << std::endl << std::endl;
    // we're starting from the end of the interval, due to the condition that says
    // the second derivative must have same sign as function.
}