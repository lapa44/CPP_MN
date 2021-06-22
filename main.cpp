#include <iostream>
#include "task10_1.h"
#include "task10_2.h"


int main() {

    //std::cout << "Metoda 100064: " << task10_1a(-3, 2, 0.0001, 1) << "\n";
    //std::cout << "Metoda Newtona: " << task10_1b(2, 0.0001); // zaczynamy od konca przedzialu, wynika to z warunku
    // ze 2 pochodna musi miec ten sam znak co funkcja.

    task10_1(-3, 2, 0.0001, 1);
    task10_2(1, 5, 0.00001);
    //zamienic jeszcze to tak, zeby n sie zmienialo przy nie osiagnieciu EPS


    return 0;
}