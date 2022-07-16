#include <Input.h>

bool InputSystem::IsButtonJustPressed(int button) {
    return Al::SetHas(ButtonsJustPressed, button);
}