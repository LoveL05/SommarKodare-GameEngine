#include <Input.h>

void InputSystem::ButtonReleased(int button) {
    if (Al::SetHas(ButtonsPressed, button)) {
        ButtonsPressed.erase(button);
        ButtonsJustReleased.insert(button);
    }
}