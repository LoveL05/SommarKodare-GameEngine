#ifndef INPUT_SYSTEM_H_
#define INPUT_SYSTEM_H_

#include <SDL3/SDL.h>
#include <iostream>
#include <Vectors.h>
#include <set>

class InputSystem {
    public:
        static std::set<int> ButtonsPressed, ButtonsJustPressed, ButtonsJustReleased;
        void ButtonPressed(int button);
        void ButtonReleased(int button);

        bool IsButtonJustReleased(const int button);
        bool GetButtonDown(const int button);
        bool IsButtonJustPressed(const int button);
};

#endif /* INPUT_SYSTEM_H_ */