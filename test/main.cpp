#include "cppinput/keyboard/kb_keys.hh"
#include "cppinput/keyboard/keyboard.hh"

int main() {
  auto k = Keyboard::Init();
  while (1) {
    if (k->IsPressed()) {
      std::cout << "pressionaod: " << k->GetCode() << std::endl;
    }
    if (k->IsKeyPressed(K_A)) {
      std::cout << "PRESSIONADO A" << std::endl;
    }
  }
}
