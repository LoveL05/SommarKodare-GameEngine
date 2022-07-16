#ifndef FED070C0_B471_48FE_9DB4_C26DE47A4B58
#define FED070C0_B471_48FE_9DB4_C26DE47A4B58

#include <SDL2/SDL.h>
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

#endif /* FED070C0_B471_48FE_9DB4_C26DE47A4B58 */