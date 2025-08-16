#ifdef _WIN32

#ifndef _WINDOWSKEYBOARD_HH_
#define _WINDOWSKEYBOARD_HH_

#include "input/keyboard/internal/ikeyboard.hpp"
#include "input/keyboard/kbkeys.hpp"
#include <windows.h>

namespace Backend {

class WindowsKeyboard : public Keyboard::IKeyboard {
public:
    WindowsKeyboard() 
    {
        instance = this;
        hookDescriptor = nullptr;
        keyStateType = 0;
        hookStruct = nullptr;
    }

    void Run() override 
    {
        hookDescriptor = SetWindowsHookEx(WH_KEYBOARD_LL, WindowsKeyboard::LowLevelKeyboardProc, nullptr, 0);
    }

    void Stop() override 
    {
        if(hookDescriptor) {
            UnhookWindowsHookEx(hookDescriptor);
            hookDescriptor = nullptr;
        }
        return;
    }
    bool IsPressed() override 
    {
        if (keyStateType == WM_KEYDOWN || keyStateType == WM_SYSKEYDOWN) {
            return true;
        }
        return false;
    }

    bool IsReleased() override  {
        if (keyStateType == WM_KEYUP || keyStateType == WM_SYSKEYUP) {
            return true;
        }
        return false;
    }

    bool IsKeyPressed(Keyboard::KB_KEYS key) override {
        if (key == static_cast<Keyboard::KB_KEYS>(hookStruct->scanCode)) 
        {
            return IsPressed();
        }
        return false;
    }

    int GetCode() override {
        return 1; // Placeholder return value, should be replaced with actual logic
    }
    private:
    static WindowsKeyboard *instance;
    HHOOK hookDescriptor;
    WPARAM keyStateType;
    KBDLLHOOKSTRUCT *hookStruct;
    
    static LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
    {
        if(nCode == HC_ACTION) {
            instance->hookStruct = reinterpret_cast<KBDLLHOOKSTRUCT *>(lParam);
            instance->keyStateType = wParam;
        }
    }
};

    

} // namespace Backend

#endif // _WINDOWSKEYBOARD_HH_
#endif // _WIN32
