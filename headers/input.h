#ifndef INPUT_SYSTEM_H_
#define INPUT_SYSTEM_H_

#include <SDL3/SDL.h>
#include <iostream>
#include <set>

#include "vectors.h"

class Engine;

class InputSystem {
    friend class Engine;
public:
    void buttonPressed(int button);
    void buttonReleased(int button);
    
    bool isButtonJustReleased(const int button);
    bool getButtonDown(const int button);
    bool isButtonJustPressed(const int button);

private:
    static std::set<int> m_buttonsPressed, m_buttonsJustPressed, m_buttonsJustReleased;
};

#endif /* INPUT_SYSTEM_H_ */