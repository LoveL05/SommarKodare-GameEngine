#include "Input.h"

std::set<int> InputSystem::ButtonsPressed = std::set<int>();
std::set<int> InputSystem::ButtonsJustPressed = std::set<int>();
std::set<int> InputSystem::ButtonsJustReleased = std::set<int>();

void InputSystem::ButtonPressed(int button) {
    if (!Al::SetHas(ButtonsPressed, button)) {
        ButtonsPressed.insert(button);
        ButtonsJustPressed.insert(button);
    }
}

void InputSystem::ButtonReleased(int button) {
    if (Al::SetHas(ButtonsPressed, button)) {
        ButtonsPressed.erase(button);
        ButtonsJustReleased.insert(button);
    }
}

bool InputSystem::GetButtonDown(int button) {
    return Al::SetHas(ButtonsPressed, button);
}

bool InputSystem::IsButtonJustPressed(int button) {
    return Al::SetHas(ButtonsJustPressed, button);
}

bool InputSystem::IsButtonJustReleased(int button) {
    return Al::SetHas(ButtonsJustReleased, button);
}
