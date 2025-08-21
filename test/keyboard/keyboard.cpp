#include "input/keyboard.hpp"

int main() {
  Keyboard::IKeyboard *kb = Keyboard::GetBackend();
  while (kb->Listen()) {
    if (kb->IsPressed()) {
      std::cout << "pressed" << std::endl;
    }
    if (kb->IsKeyPressed(Keyboard::KKB_0)) {
      break;
    }
  }
  kb->Stop();
  std::cout << "keyboard parou de ser lido..." << std::endl;
}
