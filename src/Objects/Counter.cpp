#include "Counter.hpp"

#include <iostream>

int Counter::size() {
    return sizeof(Counter);
}



void Counter::update() {
    value++;
    system("clear");
    printf("Value: %i\n", value);
}