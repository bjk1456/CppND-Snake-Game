#ifndef COBRA_H
#define COBRA_H

#include "snake.h"

class Cobra : public Snake {

public:
  Cobra(int grid_width, int grid_height, bool userVarCobraGrowing)
      : Snake(grid_width, grid_height),
        userVarCobraGrowing(userVarCobraGrowing) {}


bool userVarCobraGrowing;

bool GetGrowing();
SDL_Point the_food;
void GrowBody() override;
void setFoodLoc(SDL_Point food);
void FindClosestNode();

};

#endif