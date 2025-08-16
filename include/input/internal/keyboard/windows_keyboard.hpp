#ifdef _WIN32

#ifndef _WINDOWSKEYBOARD_HH_
#define _WINDOWSKEYBOARD_HH_

#include "input/internal/keyboard/ikeyboard.hpp"
#include "input/internal/keyboard/kbkeys.hpp"
#include <windows.h>

namespace Backend {

class WindowsKeyboard : public Keyboard::IKeyboard {
public:
  WindowsKeyboard() : lastPressedKey(0), lastReleasedKey(0) {
    for (int i = 0; i < 256; i++) {
      previousKeyStates[i] = false;
    }
  }

  void Run() override { UpdateAllKeyStates(); }

  void Stop() override {
    lastPressedKey = 0;
    lastReleasedKey = 0;
  }

  bool IsPressed() override {
    UpdateAllKeyStates();
    return lastPressedKey != 0;
  }

  bool IsReleased() override {
    UpdateAllKeyStates();
    return lastReleasedKey != 0;
  }

  bool IsKeyPressed(Keyboard::KB_KEYS key) override {
    int vkCode = ConvertToVirtualKey(key);
    if (vkCode == 0)
      return false;

    return (GetAsyncKeyState(vkCode) & 0x8000) != 0;
  }

  int GetCode() override {
    UpdateAllKeyStates();
    return lastPressedKey != 0 ? lastPressedKey : lastReleasedKey;
  }

private:
  bool previousKeyStates[256];
  int lastPressedKey;
  int lastReleasedKey;

  void UpdateAllKeyStates() {
    lastPressedKey = 0;
    lastReleasedKey = 0;

    for (int vk = 0; vk < 256; vk++) {
      bool currentState = (GetAsyncKeyState(vk) & 0x8000) != 0;
      bool previousState = previousKeyStates[vk];

      if (currentState && !previousState) {
        lastPressedKey = vk;
      } else if (!currentState && previousState) {
        lastReleasedKey = vk;
      }

      previousKeyStates[vk] = currentState;
    }
  }

  int ConvertToVirtualKey(Keyboard::KB_KEYS key) {
    switch (key) {
      // Letras
      // case Keyboard::KB_A: return 'A';
      // case Keyboard::KB_B: return 'B';
      // ...

      // Números
      // case Keyboard::KB_0: return '0';
      // case Keyboard::KB_1: return '1';
      // ...

      // Teclas especiais
      // case Keyboard::KB_SPACE: return VK_SPACE;
      // case Keyboard::KB_ENTER: return VK_RETURN;
      // case Keyboard::KB_ESC: return VK_ESCAPE;
      // case Keyboard::KB_SHIFT: return VK_SHIFT;
      // case Keyboard::KB_CTRL: return VK_CONTROL;
      // case Keyboard::KB_ALT: return VK_MENU;

    default:
      return static_cast<int>(key);
    }
  }
};

} // namespace Backend

#endif // _WINDOWSKEYBOARD_HH_
#endif // _WIN32
