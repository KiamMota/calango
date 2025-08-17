#include "input/keyboard.hpp"

int main() {
  Keyboard::IKeyboard *kb = Keyboard::GetBackend();
  while (kb->Listen()) {
    if (kb->IsPressed())
      std::cout << kb->GetKey() << std::endl;
  }
}
