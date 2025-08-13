#include "cppinput/keyboard/kb_keys.hh"
#include "cppinput/keyboard/keyboard.hh"

int main() {
  KB_KEYS a = KEY_A;
  auto k = Keyboard::Init();
  while (1) {
    if (k->IsPressed()) {
      std::cout << "presisonado!" << std::endl;
    }
    if (k->IsKeyPressed(KEY_A)) {
      std::cout << "pressionado A" << std::endl;
    }
  }
}
