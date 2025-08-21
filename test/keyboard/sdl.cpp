#include "input/keyboard.hpp"
#include <SDL2/SDL.h>
#include <iostream>

void RunWindow() {
  SDL_Init(SDL_INIT_VIDEO);
  SDL_Window *win =
      SDL_CreateWindow("Calango SDL Wayland", SDL_WINDOWPOS_CENTERED,
                       SDL_WINDOWPOS_CENTERED, 400, 300, 0);

  auto *kb = Keyboard::GetBackend();
  bool running = true;
  bool focused = true;

  while (running && kb->Listen()) {
    SDL_Event ev;
    while (SDL_PollEvent(&ev)) {
      // Fechar janela no Wayland/GNOME
      if (ev.type == SDL_QUIT || (ev.type == SDL_WINDOWEVENT &&
                                  ev.window.event == SDL_WINDOWEVENT_CLOSE)) {
        running = false;
      }

      if (ev.type == SDL_WINDOWEVENT) {
        if (ev.window.event == SDL_WINDOWEVENT_FOCUS_GAINED) {
          focused = true;
          kb->Listen(); // retoma escuta se necessário
        }
        if (ev.window.event == SDL_WINDOWEVENT_FOCUS_LOST) {
          focused = false;
          kb->Stop(); // pausa escuta enquanto não há foco
        }
      }
    }

    if (!focused)
      continue;

    if (kb->IsKeyPressed(Keyboard::KKB_0)) {
      std::cout << "Tecla 0 pressionada, saindo..." << std::endl;
      running = false;
    } else if (kb->IsPressed()) {
      std::cout << "Alguma tecla foi pressionada dentro da janela."
                << std::endl;
    }
  }

  SDL_DestroyWindow(win);
  SDL_Quit();
}

int main() {
  RunWindow();
  return 0;
}
