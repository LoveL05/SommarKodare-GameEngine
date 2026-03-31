#include "input.h"

std::set<int> InputSystem::m_buttonsPressed = std::set<int>();
std::set<int> InputSystem::m_buttonsJustPressed = std::set<int>();
std::set<int> InputSystem::m_buttonsJustReleased = std::set<int>();

void InputSystem::buttonPressed(int button) {
    if (!Al::doesSetContain(m_buttonsPressed, button)) {
        m_buttonsPressed.insert(button);
        m_buttonsJustPressed.insert(button);
    }
}

void InputSystem::buttonReleased(int button) {
    if (Al::doesSetContain(m_buttonsPressed, button)) {
        m_buttonsPressed.erase(button);
        m_buttonsJustReleased.insert(button);
    }
}

bool InputSystem::getButtonDown(int button) {
    return Al::doesSetContain(m_buttonsPressed, button);
}

bool InputSystem::isButtonJustPressed(int button) {
    return Al::doesSetContain(m_buttonsJustPressed, button);
}

bool InputSystem::isButtonJustReleased(int button) {
    return Al::doesSetContain(m_buttonsJustReleased, button);
}
