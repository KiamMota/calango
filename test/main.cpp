
#include "input/keyboard/getbackend.hpp"
#include "input/mouse/getbackend.hpp"
#include "input/mouse/imouse.hpp"
#include <ctime>
int main() {
  Keyboard::IKeyboard *kb = Keyboard::GetBackend();
  Mouse::IMouse *ms = Mouse::GetBackend();

  while (1) {
    if (ms->IsReleased()) {
      std::cout << "solto!" << std::endl;
    }
  }
}
