#include "input/keyboard/getbackend.hpp"
#include "input/keyboard/ikeyboard.hpp"
int main() {
  Keyboard::IKeyboard *kb = Keyboard::GetBackend();
  kb->Run();
  while (1) {
    if (kb->IsPressed()) {
      std::cout << "esta pressionando alguma coisa" << std::endl;
    }
  }
}
