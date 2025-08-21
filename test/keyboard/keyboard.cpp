#include "input/keyboard.hpp"
<<<<<<< HEAD
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
=======
#include <SDL_events.h>
#include <SDL_timer.h>

void hello() { std::cout << "hello! pressed key!" << std::endl; }
int main() {
  Keyboard::IKeyboard *kb = Keyboard::GetBackend();

  SDL_Event event;
  int running = 1;
  while (running) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT)
        running = 0;
    }
    SDL_Delay(16);
  }
>>>>>>> afe1a56 (refac : directory structures)
}
