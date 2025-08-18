#include "input/keyboard.hpp"

void hello() { std::cout << "hello! pressed key!" << std::endl; }
int main() { Keyboard::IKeyboard *kb = Keyboard::GetBackend(); }
