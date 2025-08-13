#include "cppinput/backend/ikeyboard.hh"
#include "cppinput/keyboard/kb_keys.hh"
#include "cppinput/keyboard/keyboard.hh"

int main() {
  Keyboard::IKeyboard *k = Keyboard::GetKeyboard();
  while (1) {
    if (k->IsPressed()) {
      std::cout << "pressionaod: " << k->GetCode() << std::endl;
    }
    if (k->IsKeyPressed(Keyboard::K_A)) {
      std::cout << "PRESSIONADO A" << std::endl;
    }
  }
}
