#include <Input.h>

bool InputSystem::GetButtonDown(int button) {
    return Al::SetHas(ButtonsPressed, button);
}