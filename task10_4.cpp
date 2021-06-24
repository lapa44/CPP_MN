#include <iostream>
#include "task10_4.h"
#include "task10_3.h"

double lagrangeInterpolation(const std::vector<double>& xVector, const std::vector<double>& yVector, double x, int n) {
    double result = 0;
    for (int i=0; i<n; i++) {
        double temp = yVector.at(i);
        for (int j=0; j<n; j++)
        {
            if (j!=i)
                temp = temp * (x - xVector.at(j)) / double(xVector.at(i) - xVector.at(j));
        }
        result += temp;
    }
    return result;
}

void task10_4(double xp, double xk, double h, const std::vector<double>& xVector, const std::vector<double>& yVector) {
    std::cout << "Lagrange Method is printing:\nx\tf(x)\t\tF(x) = a * b^x" << std::endl;
    for (double i=xp; i<xk+h; i+=h) {
        std::cout << i << "\t" << lagrangeInterpolation(xVector, yVector, i, 5) << "\t\t" << aproFunction10_3(i) << std::endl;
    }
    std::cout << std::endl;
}
