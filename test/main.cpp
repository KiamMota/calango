#include "input/keyboard/ikeyboard.hpp"
#include "input/keyboard/kb_keys.hh"
#include "input/keyboard/start.hh"

int main() {
  auto k = Keyboard::Start();
  while (1) {
    if (k->IsKeyPressed(Keyboard::K_4)) {
      std::cout << "pressionado C" << std::endl;
    }
  }
}
