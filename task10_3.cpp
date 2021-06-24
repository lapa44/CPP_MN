#include "task10_3.h"
#include <math.h>
#include <iostream>

double aproFunction10_3(double x) {
    return 1.3 * pow(2.09, x);
}

void task10_3(int xp, int xk, double h) {

    std::cout << "Program is printing:\nx\tf(x)" << std::endl;
    for (double i = xp; i <xk + h; i += h) {
        std::cout << i << "\t" << aproFunction10_3(i) << std::endl;
    }
    std::cout << std::endl;
}
