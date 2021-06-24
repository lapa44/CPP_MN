#include <iostream>
#include "task10_1.h"
#include "task10_2.h"
#include "task10_3.h"
#include "task10_4.h"


int main() {

    std::cout <<  "Task  10_1:\n";
    task10_1(-3, 2, 0.0001, 1);
    std::cout <<  "Task  10_2:\n";
    task10_2(1, 5, 0.00001);
    std::cout <<  "Task  10_3:\n";
    task10_3(0, 4, 0.1);
    std::cout <<  "Task  10_4:\n";
    task10_4(0, 4,  0.2, {0, 0.5, 1, 3, 4}, {1.2, 1.92, 3, 11.6, 24.4});

    return 0;
}