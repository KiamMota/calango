#include "input/internal/keyboard/kbkeys.hpp"
#include "input/keyboard.hpp"
#include <iostream>

void DefaultTest(Keyboard::IKeyboard *kb) {
  if (kb->IsPressed()) {
    std::cout << "pressing correctly" << std::endl;
  }

  if (kb->IsReleased()) {
    std::cout << "releasing correctly" << std::endl;
  }
}

int main() {
  auto *kb = Keyboard::GetBackend();
  while (kb->Run()) {
    DefaultTest(kb);
    if (kb->IsKeyPressed(Keyboard::KBB_ENTER)) {
      std::cout << "pressed: " << "ENTER!" << std::endl;
    }
  }
}
