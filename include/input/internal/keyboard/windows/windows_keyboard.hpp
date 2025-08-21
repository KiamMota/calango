#ifdef _WIN32

#ifndef _WINDOWSKEYBOARD_HH_
#define _WINDOWSKEYBOARD_HH_

#include "input/internal/keyboard/ikeyboard.hpp"
#include "input/internal/keyboard/kbkeys.hpp"
#include <windows.h>
#include <functional>

namespace Backend {

class WindowsKeyboard : public Keyboard::IKeyboard {
public:
  WindowsKeyboard() : lastPressedKey(static_cast<Keyboard::KB_KEYS>(0)), 
                      lastReleasedKey(static_cast<Keyboard::KB_KEYS>(0)) {
    for (int i = 0; i < 256; i++) {
      previousKeyStates[i] = false;
    }
  }

  bool Listen() override { 
    UpdateAllKeyStates(); 
  }

  void Stop() override {
    lastPressedKey = static_cast<Keyboard::KB_KEYS>(0);
    lastReleasedKey = static_cast<Keyboard::KB_KEYS>(0);
  }

  bool IsPressed() override { 
    return static_cast<int>(lastPressedKey) != 0; 
  }

  bool IsReleased() override { 
    return static_cast<int>(lastReleasedKey) != 0; 
  }

  void IsPressed(std::function<void()> callback) override {
    while (true) {
      Listen();
      if (IsPressed()) {
        callback();
        return;
      }
    }
  }

  void IsReleased(std::function<void()> callback) override {
    while (true) {
      Listen();
      if (IsReleased()) {
        callback();
        return;
      }
    }
  }

  bool IsKeyPressed(Keyboard::KB_KEYS key) override {
    int vkCode = static_cast<int>(key);
    return (GetAsyncKeyState(vkCode) & 0x8000) != 0;
  }

  bool IsKeyReleased(Keyboard::KB_KEYS key) override {
    int vkCode = static_cast<int>(key);
    bool currentState = (GetAsyncKeyState(vkCode) & 0x8000) != 0;
    bool previousState = previousKeyStates[vkCode];
    
    return !currentState && previousState;
  }

  Keyboard::KB_KEYS GetKey() override {
    return static_cast<int>(lastPressedKey) != 0 ? lastPressedKey : lastReleasedKey;
  }

private:
  bool previousKeyStates[256];
  Keyboard::KB_KEYS lastPressedKey;
  Keyboard::KB_KEYS lastReleasedKey;

  void UpdateAllKeyStates() {
    lastPressedKey = static_cast<Keyboard::KB_KEYS>(0);
    lastReleasedKey = static_cast<Keyboard::KB_KEYS>(0);

    for (int vk = 0; vk < 256; vk++) {
      bool currentState = (GetAsyncKeyState(vk) & 0x8000) != 0;
      bool previousState = previousKeyStates[vk];

      if (currentState && !previousState) {
        lastPressedKey = static_cast<Keyboard::KB_KEYS>(vk);
      } else if (!currentState && previousState) {
        lastReleasedKey = static_cast<Keyboard::KB_KEYS>(vk);
      }

      previousKeyStates[vk] = currentState;
    }
  }
};

} 

#endif // _WINDOWSKEYBOARD_HH_
#endif // _WIN32