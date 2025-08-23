#ifdef _WIN32

#ifndef _WINDOWSKB_HPP_
#define _WINDOWSKB_HPP_

#include <Windows.h>
#include <input/internal/keyboard/ikeyboard.hpp>

namespace Backend {

class WindowsKeyboard : public Keyboard::IKeyboard 
{
    public:
        WindowsKeyboard()
        {
            for (short i = 0; i < 256; ++i) prevState[i] = false;
        }
        ~WindowsKeyboard()
        {
            // Cleanup if necessary
        }
        bool Listen() override
        {
            stopFlag = false;
            UpdateKeyScan();
            return true;
        }
        void Stop() override
        {
            stopFlag = true;
            UpdateKeyVars();
        }
        bool IsPressed() override
        {
            return isPressed;
        }
        bool IsReleased() override
        {
            return isReleased;
        }
        void IsPressed(std::function<void()> callback) override
        {
            while(true)
            {
                if(isPressed) callback();
                UpdateKeyScan();
                if(stopFlag) break;
            }
        }
        void IsReleased(std::function<void()> callback) override
        {
            while(true)
            {
                if(isReleased) callback();
                UpdateKeyScan();
                if(stopFlag) break;
            }
        }
        bool IsKeyPressed(Keyboard::KB_KEYS kb) override
        {
            return (GetAsyncKeyState(static_cast<int>(kb)) & 0x8000) != 0;
        }
        bool IsKeyReleased(Keyboard::KB_KEYS kb) override
        {
            return (GetAsyncKeyState(static_cast<int>(kb)) & 0x8000) == 0;
        }
        Keyboard::KB_KEYS GetKey() override
        {
            return static_cast<Keyboard::KB_KEYS>(virtualKey);
        }

    private:
        void UpdateKeyVars()
        {
            isPressed = false;
            isReleased = false;    
        }

        void UpdateKeyScan()
        {
            if(stopFlag) return;
            UpdateKeyVars();
            for(virtualKey = 0x08; virtualKey <= 0xFE; ++virtualKey)
            {
                bool pressedNow = (GetAsyncKeyState(virtualKey) & 0x8000) != 0;
                if(pressedNow && !prevState[virtualKey]) isPressed = true;
                if(!pressedNow && prevState[virtualKey]) isReleased = true;
                prevState[virtualKey] = pressedNow;
            }
        }
        bool stopFlag;
        int virtualKey;
        bool isPressed;
        bool isReleased;
        
        bool prevState[256];
};
} // namespace Backend

#endif //_WINDOWSKB_HPP_
#endif //_WIN32