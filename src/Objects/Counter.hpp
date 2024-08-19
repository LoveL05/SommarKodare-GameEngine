#ifndef OBJ_COUNTER_HPP
#define OBJ_COUNTER_HPP

#include "../UpdateableObject/UpdateableObject.hpp"

class Counter: public UpdateableObject {
    int value = 0;
public:
    void update();
};

#endif // OBJ_COUNTER_HPP