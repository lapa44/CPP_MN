#include <iostream>
#include "task10_2.h"

float function10_2(float x) {
    return (1/(2*x + 3)) + 3*x*x;
}

void prostokaty_10_2(float xp, float xk, int n) {

    float dx = (xk-xp) / (float)n;

    float rezultat = 0;

    for (int i=1; i<=n; i++) {
        rezultat += function10_2(xp + (float)i * dx);
        rezultat *= dx;
        std::cout << "Prostokaty krok "  <<  i << ": " << rezultat << "\n";
    }
    std::cout << "Metoda prostokatow: " << rezultat << "\n";

}

void trapezy_10_2(float xp, float xk, int n) {

    float dx = (xk-xp) / (float)n;

    float rezultat = 0;

    for (int i=1; i<n; i++) {
        rezultat += function10_2(xp + (float)i * dx);
        //rezultat += (function10_2(xp) + function10_2(xk)) / 2;
        rezultat = (rezultat + (function10_2(xp) + function10_2(xk)) / 2) * dx;
        std::cout << "Trapezy krok "  <<  i << ": " << rezultat << "\n";
    }
    std::cout << "Metoda Trapezow: " << rezultat << "\n";

}

void task10_2(float xp, float xk, float n) {
    prostokaty_10_2(xp, xk, n);
    trapezy_10_2(xp, xk, n);
}