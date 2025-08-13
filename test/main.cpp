#include "cppinput/keyboard.hh"
#include <iostream>

int main() {
  auto k = Keyboard::Init();
  while (1) {
    if (k->IsPressed()) {
      std::cout << "presisonado!" << std::endl;
    }
  }
}
