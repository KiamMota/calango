#include "input/mouse.hpp"
#include "input/internal/mouse/imouse.hpp"
#include "input/internal/mouse/linux_mskeys.hpp"

#define L "<LEFT>"
#define R "<RIGHT>"
#define M "<MIDDLE>"
#define PR "[PRESSED]"
#define RL "[RELEASED]"
#define print std::cout
#define end std::endl

void LeftPressed(Mouse::IMouse *a) {
  if (a->IsButtonPressed(Mouse::MMS_LEFT)) {
    print << L << PR << end;
  }
  if (a->IsButtonReleased(Mouse::MMS_LEFT)) {
    print << L << RL << end;
  }
}

void RightPressed(Mouse::IMouse *a) {
  if (a->IsButtonPressed(Mouse::MMS_RIGHT)) {
    print << R << PR << end;
  }
  if (a->IsButtonReleased(Mouse::MMS_RIGHT)) {
    print << R << RL << end;
  }
}

int main() {
  auto *ms = Mouse::GetBackend();
  while (ms->Listen()) {
    LeftPressed(ms);
    RightPressed(ms);
  }
}
