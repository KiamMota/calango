#include "input/keyboard.hpp"
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
    if (kb->IsKeyPressed(Keyboard::KKB_0)) {
      std::cout << "zero is pressed!" << std::endl;
      Keyboard::Free(&kb);
      break;
    }
  }

  std::cout << "exited with no errors." << std::endl;
}
