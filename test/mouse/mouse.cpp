#include "input/mouse.hpp"

int main() {
  Mouse::IMouse *ms = Mouse::GetBackend();

  while (ms->Listen()) {
    if (ms->IsMoving()) {
      std::cout << "mouse is moving" << std::endl;
    }
    if (ms->IsButtonPressed(Mouse::MMS_LEFT)) {
      break;
    }
  }
  ms->Stop();
}
