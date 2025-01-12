#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "garter.h"

void Controller::ChangeDirection(Garter &garter, Garter::Direction input,
                                 Garter::Direction opposite) const {
  if (garter.direction != opposite || garter.size == 1) garter.direction = input;
  return;
}

void Controller::HandlePredatorMovement(Cobra &cobra) const {

      int diff_x = static_cast<int>(cobra.head_x) - cobra.the_food.x;
    int diff_y = static_cast<int>(cobra.head_y) - cobra.the_food.y;

    std::cout << "diff_x ==";
    std::cout << abs(diff_x);
    std::cout << "\n";
     std::cout << "diff_y ==";
    std::cout << abs(diff_y);
     std::cout << "\n";

     if((abs(diff_x)) > abs(diff_y)){
      if(diff_x < 0){
          cobra.direction = Cobra::Direction::kRight;
      }
      else{
        cobra.direction = Cobra::Direction::kLeft;
      }
      return;
     }
      if((abs(diff_y)) > abs(diff_x)){
      if(diff_y < 0){
          cobra.direction = Cobra::Direction::kDown;
      }
      else{
        cobra.direction = Cobra::Direction::kUp;
      }
      return;
     }

  //if (cobra.direction != opposite || cobra.size == 1) cobra.direction = input;
  return;
}



void Controller::HandleInput(bool &running, Garter &garter, Cobra &cobra) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      //cobra.CalculateMove();
      HandlePredatorMovement(cobra);
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

