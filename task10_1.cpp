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
        //std::cout << "Przyblizenie nr " << counter << "=\t"  << result << "dla x = " << i << "\n";
        if (result == 0 || std::abs(result) < eps) {
            std::cout << "Liczba operacji: " << counter << "\n";
            return i;
        }
    }
    return task10_1a(xp, xk, eps, incrementer / 6, counter); // bylo /10, ale liczba operacji była x10
}



double task10_1b(double x, double eps) {

    double f0 = function10_1(x), x0 = x;

    while (fabs(f0) > eps) {
        x = x0;
        x0 = x - f0 / derivative10_1(x);
        f0 = function10_1(x0);
        std::cout << "Przyblizono " << f0 << " dla x = " << x0 << "\n";
    }
    return x0;
}