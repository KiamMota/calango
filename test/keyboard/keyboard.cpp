#include "input/keyboard.hpp"
#include <iostream>

void hello() 
{ 
    std::cout << "hello! pressed key!" << std::endl;
 }
int main() 
{ 
    std::cout << "init" << std::endl;
    Keyboard::IKeyboard *kb = Keyboard::GetBackend();
    while(kb->Listen())
    {
        if(kb->IsPressed()) {std::cout << "something is pressed! " << std::endl;}
    }
}
