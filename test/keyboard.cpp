#include "input/keyboard/keyboard.hpp"
#include "input/keyboard/kbkeys.hpp"

int main() {
  Keyboard::IKeyboard *kb = Keyboard::GetBackend();
  kb->Run();
  while (1) {
    if (kb->IsPressed()) {
      std::cout << "esta pressionando alguma coisa" << std::endl;
    }
    //implementação da checagem de teclas
    if (kb->IsKeyPressed(Keyboard::KB_KEYS::K_A)) {
      std::cout << "A tecla A está pressionada!" << std::endl;
    }
  }
}
