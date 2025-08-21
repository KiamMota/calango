#include "input/keyboard.hpp"
#include <SDL2/SDL.h>
#include <iostream>

void RunWindow() {
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    std::cerr << "Erro ao inicializar SDL: " << SDL_GetError() << std::endl;
    return;
  }

  SDL_Window *win = SDL_CreateWindow(
      "Calango SDL Wayland", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
      400, 300, SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI);

  if (!win) {
    std::cerr << "Erro ao criar a janela: " << SDL_GetError() << std::endl;
    SDL_Quit();
    return;
  }

  // Cria uma superfície associada à janela
  SDL_Surface *surface = SDL_GetWindowSurface(win);
  if (!surface) {
    std::cerr << "Erro ao criar a superfície: " << SDL_GetError() << std::endl;
    SDL_DestroyWindow(win);
    SDL_Quit();
    return;
  }

  auto *kb = Keyboard::GetBackend();
  bool running = true;
  bool focused = true;

  while (running && kb->Listen()) {
    SDL_Event ev;
    while (SDL_PollEvent(&ev)) {
      if (ev.type == SDL_QUIT || (ev.type == SDL_WINDOWEVENT &&
                                  ev.window.event == SDL_WINDOWEVENT_CLOSE)) {
        running = false;
      }

      if (ev.type == SDL_WINDOWEVENT) {
        if (ev.window.event == SDL_WINDOWEVENT_FOCUS_GAINED) {
          focused = true;
          kb->Listen();
        }
        if (ev.window.event == SDL_WINDOWEVENT_FOCUS_LOST) {
          focused = false;
        }
      }
    }

    if (!focused)
      continue;

    // Preenche a superfície com cor
    SDL_FillRect(surface, nullptr, SDL_MapRGB(surface->format, 50, 100, 150));
    SDL_UpdateWindowSurface(win);

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
