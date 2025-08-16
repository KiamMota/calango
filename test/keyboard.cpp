#include "input/keyboard/keyboard.hpp"
#include "input/keyboard/kbkeys.hpp"

int main() {
  Keyboard::IKeyboard *kb = Keyboard::GetBackend();
  kb->Run();
  while (1) {
    if (kb->IsPressed())
      std::cout << "presisonou algo asmfdiafdsagf ads" << std::endl;
    if (kb->IsKeyPressed(Keyboard::K_A)) {
      std::cout << "PRESSIONOU A" << std::endl;
    }
    std::cout << kb->GetCode() << std::endl;
  }
}
