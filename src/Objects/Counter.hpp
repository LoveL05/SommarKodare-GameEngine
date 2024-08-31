#ifndef OBJ_COUNTER_HPP
#define OBJ_COUNTER_HPP

#include "../UpdateableObject/UpdateableObject.hpp"

class Counter: public UpdateableObject {
    int value = 0;
    char buffer[128] = {0};
public:
    ~Counter() = default;
    void update();
    int size();
};

#endif // OBJ_COUNTER_HPP