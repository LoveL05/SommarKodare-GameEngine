#include <Input.h>

bool InputSystem::IsButtonJustReleased(int button) {
    return Al::SetHas(ButtonsJustReleased, button);
}