#include "input/mouse.hpp"

#include <iostream>

int main() {
  Mouse::IMouse *ms = Mouse::GetBackend();

  while (ms->Listen()) {
    if (ms->IsMoving()) {
      std::cout << "mouse is moving" << std::endl;
    }
    if(ms->IsPressed()) {
      std::cout << "mouse is pressed" << std::endl;
    }

  }
  ms->Stop();
}
