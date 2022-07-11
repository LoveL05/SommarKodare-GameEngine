#include <Input.h>

bool InputSystem::GetButtonJustPressed(int button) {
    return Al::SetHas(ButtonsJustPressed, button);
}