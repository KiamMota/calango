#include "input/keyboard.hpp"

int main() {
  Keyboard::IKeyboard *kb = Keyboard::GetBackend();
  while (kb->Run()) {
    if (kb->IsPressed())
      std::cout << "presisonou algo asmfdiafdsagf ads" << std::endl;
    if (kb->IsKeyPressed(Keyboard::K_A)) {
      std::cout << "PRESSIONOU A" << std::endl;
    }
    std::cout << kb->GetCode() << std::endl;
  }
}
