#include <iostream>
#include "task10_2.h"

double function10_2(double x) {
    return (1/(2*x + 3)) + 3*x*x;
}

double prostokaty_10_2(double xp, double xk, int n) {
    int counter = 0;
    double dx = (xk-xp) / (double)n;

    double rezultat = 0;

    for (int i=1; i<=n; i++) {
        counter++;
        rezultat += function10_2(xp + (double)i * dx);
        std::cout << "Prostokaty krok "  <<  i << ": " << rezultat << "\n";
    }
    std::cout << "Liczba operacji w metodzie prostokatow: " << counter << "\n";
    return rezultat * dx;
}

double trapezy_10_2(double xp, double xk, int n) {
    int counter = 0;
    double dx = (xk-xp) / (double)n;
    double rezultat = 0;
    for (int i=1; i<n; i++) {
        counter++;
        rezultat += function10_2(xp + (double)i * dx);
    }
    std::cout << "Liczba operacji w metodzie trapezow: " << counter << "\n";
    return (rezultat + (function10_2(xp) + function10_2(xk)) / 2) * dx;
}

void task10_2(double xp, double xk, int n) {
    double eps = 0.00001;
    std::cout << "Rezultat metoda prostokatow: " << prostokaty_10_2(xp, xk, n) << "\n";
    std::cout << "Rezultat metoda trapezow: "<< trapezy_10_2(xp, xk, n) << "\n"; // 124-125 dobry wynik :D
}
