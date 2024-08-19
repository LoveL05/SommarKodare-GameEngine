#include "Counter.hpp"

#include <iostream>

void Counter::update() {
    value++;
    system("clear");
    printf("Value: %i\n", value);
}