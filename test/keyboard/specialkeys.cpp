#include "input/internal/keyboard/ikeyboard.hpp"
#include "input/internal/keyboard/kbkeys.hpp"
#include "input/keyboard.hpp"
#include <cstdlib>
#include <iostream>

static int messages = 0;

void ClearMessages() {

  if (messages >= 21) {
#ifdef __linux__
    system("clear");
#endif

    messages = 0;
  }
}

void Pressed(Keyboard::IKeyboard *kb, Keyboard::KB_KEYS kben,
             const char *message) {
  if (kb->IsKeyPressed(kben)) {
    std::cout << ">>> PRESSED >>> " << message << std::endl;
  }
}
void PressedQuit(Keyboard::IKeyboard *kb, Keyboard::KB_KEYS kben,
                 const char *message) {
  if (kb->IsKeyPressed(kben)) {
    std::cout << ">>> PRESSED >>> " << message << std::endl;
    kb->Stop();
  }
}

void DefaultTest(Keyboard::IKeyboard *kb) {
  if (kb->IsPressed()) {
    std::cout << "PRESSING correctly" << std::endl;
  }

  if (kb->IsReleased()) {
    std::cout << "RELEASING correctly" << std::endl;
  }
}

int main() {
  auto *kb = Keyboard::GetBackend();
  while (kb->Listen()) {
    DefaultTest(kb);
    ClearMessages();
    messages++;
    Pressed(kb, Keyboard::KBB_CAPSLOCK, "CAPSLOCK");
    Pressed(kb, Keyboard::KBB_SPACE, "SPACE");
    Pressed(kb, Keyboard::KKB_LEFTCTRL, "CTRL");
  }
}
