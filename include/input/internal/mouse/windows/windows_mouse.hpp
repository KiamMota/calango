#ifdef _WIN32
#ifndef _WINDOWSMS_HPP_
#define _WINDOWSMS_HPP_

#include "input/internal/mouse/imouse.hpp"
#include <Windows.h>
#include <functional>

namespace Backend {

class WindowsMouse : public Mouse::IMouse {
public:
    WindowsMouse() {
        GetCursorPos(&prevPos);
        for (int i = 0; i < 5; ++i) prevState[i] = false; // para cada botão que vamos monitorar
    }

    ~WindowsMouse() {}

    bool Listen() override {
        stopFlag = false;
        UpdateMouseVars();
        return true;
    }

    void Stop() override {
        stopFlag = true;
        isMoving = false;
    }

    bool IsPressed() override {
        isAnyPressed = false;
        const int buttons[5] = { VK_LBUTTON, VK_RBUTTON, VK_MBUTTON, VK_XBUTTON1, VK_XBUTTON2 };
        for (int i = 0; i < 5; ++i) {
            if (GetAsyncKeyState(buttons[i]) & 0x8000) {
                isAnyPressed = true;
                break;
            }
        }
        return isAnyPressed;
    }

    bool IsReleased() override {
        isAnyReleased = false;
        const int buttons[5] = { VK_LBUTTON, VK_RBUTTON, VK_MBUTTON, VK_XBUTTON1, VK_XBUTTON2 };
        for (int i = 0; i < 5; ++i) {
            bool pressedNow = (GetAsyncKeyState(buttons[i]) & 0x8000) != 0;
            if (!pressedNow && prevState[i]) {
                isAnyReleased = true;
                break;
            }
            prevState[i] = pressedNow;
        }
        return isAnyReleased;
    }

    void IsPressed(std::function<void()> callback) override {
        while (!stopFlag) {
            if (IsPressed()) callback();
            UpdateMouseVars();
        }
    }

    void IsReleased(std::function<void()> callback) override {
        while (!stopFlag) {
            if (IsReleased()) callback();
            UpdateMouseVars();
        }
    }

    bool IsMoving() override {
        UpdateMouseVars();
        return isMoving;
    }

    bool IsButtonPressed(Mouse::MS_BUTTONS ms) override {
        return (GetAsyncKeyState(static_cast<int>(ms)) & 0x8000) != 0;
    }

    bool IsButtonReleased(Mouse::MS_BUTTONS ms) override {
        return (GetAsyncKeyState(static_cast<int>(ms)) & 0x8000) == 0;
    }

    bool IsScrollingVertical() override { return false; }
    short GetScrollAmount() override { return 0; }

private:
    void UpdateMouseVars() {
        if (stopFlag) return;
        POINT currentPos;
        GetCursorPos(&currentPos);
        isMoving = (currentPos.x != prevPos.x || currentPos.y != prevPos.y);
        prevPos = currentPos;
    }

    int virtualKey = 0;
    bool stopFlag = false;
    POINT prevPos;
    bool isMoving = false;
    bool isAnyPressed = false;
    bool isAnyReleased = false;
    bool prevState[5] = { false }; // estado anterior de cada botão monitorado
};

} // namespace Backend

#endif
#endif
