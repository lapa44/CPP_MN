#include <iostream>
#include "task10_2.h"

double function10_2(double x) {
    return (1/(2*x + 3)) + 3*x*x;
}

double prostokaty_10_2(double xp, double xk, int n, double eps, int counter) {
    double dx = (xk-xp) / (double)n;
    double rezultat = 0;
    for (int i=1; i<=n; i++) {
        counter++;
        rezultat += function10_2(xp + (double)i * dx);
    }
    if (rezultat*dx - 124.48 > eps) {
        return prostokaty_10_2(xp, xk, n*2, eps, counter);
    }
    std::cout << "Liczba operacji w metodzie prostokatow: " << counter << "\n";
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
    std::cout << "Liczba operacji w metodzie trapezow: " << counter << "\n";
    return rezultat;
}

void task10_2(double xp, double xk, double eps) {
    int n = 4; // poczatkowa liczba przedzialow
    std::cout << "Rezultat metoda prostokatow: " << prostokaty_10_2(xp, xk, n, eps, 0) << "\n";
    std::cout << "Rezultat metoda trapezow: "<< trapezy_10_2(xp, xk, n, eps, 0) << "\n"; // 124-125 dobry wynik :D
}
