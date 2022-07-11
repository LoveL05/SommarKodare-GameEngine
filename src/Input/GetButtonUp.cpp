#include <Input.h>

bool InputSystem::GetButtonUp(int button) {
    return Al::SetHas(ButtonsJustReleased, button);
}