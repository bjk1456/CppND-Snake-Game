#ifndef GARTER_H
#define GARTER_H

#include "snake.h"

class Garter : public Snake {

public:
  Garter(int grid_width, int grid_height)
      : Snake(grid_width, grid_height) {}

void GrowBody() override;

};

#endif