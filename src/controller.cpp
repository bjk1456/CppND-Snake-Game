#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "garter.h"

void Controller::ChangeDirection(Garter &garter, Garter::Direction input,
                                 Garter::Direction opposite) const {
  if (garter.direction != opposite || garter.size == 1) garter.direction = input;
  return;
}

void Controller::HandleInput(bool &running, Garter &garter) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_UP:
          ChangeDirection(garter, Garter::Direction::kUp,
                          Garter::Direction::kDown);
          break;

        case SDLK_DOWN:
          ChangeDirection(garter, Garter::Direction::kDown,
                          Garter::Direction::kUp);
          break;

        case SDLK_LEFT:
          ChangeDirection(garter, Garter::Direction::kLeft,
                          Garter::Direction::kRight);
          break;

        case SDLK_RIGHT:
          ChangeDirection(garter, Garter::Direction::kRight,
                          Garter::Direction::kLeft);
          break;
      }
    }
  }
}