#include <Input.h>

void InputSystem::ButtonPressed(int button) {
    if (!Al::SetHas(ButtonsPressed, button)) {
        ButtonsPressed.insert(button);
        ButtonsJustPressed.insert(button);
    }
}