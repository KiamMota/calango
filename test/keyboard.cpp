#include "input/keyboard.hpp"

int main() {
  Keyboard::IKeyboard *kb = Keyboard::GetBackend();
  while (kb->Run()) {
    if (kb->IsPressed())
      std::cout << kb->GetCode() << std::endl;
  }
}
