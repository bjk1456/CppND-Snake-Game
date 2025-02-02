#include "cobra.h"
#include "controller.h"
#include <iostream>
#include <cmath>


void Cobra::GrowBody() { growing = true; }

void Cobra::setFoodLoc(SDL_Point food) {
    the_food = food;
}

void Cobra::CalculateMove() {
    std::cout << "CalculateMove() INVOKED!!!!\n";
    std::cout << "the food x ==";
    std::cout << the_food.x;
    std::cout << "\n";
     std::cout << "the food y ==";
    std::cout << the_food.y;
     std::cout << "\n";

     int cast_x = static_cast<int>(head_x);
     int cast_y = static_cast<int>(head_y);
  
     
    std::cout << "head_x ==";
    std::cout << head_x;
    std::cout << "\n";
     std::cout << "head_y ==";
    std::cout << head_y;
     std::cout << "\n";

    std::cout << "cast_x ==";
    std::cout << cast_x;
    std::cout << "\n";
     std::cout << "cast_y ==";
    std::cout << cast_y;
     std::cout << "\n";

    int diff_x = static_cast<int>(head_x) - the_food.x;
    int diff_y = static_cast<int>(head_y) - the_food.y;

    std::cout << "diff_x ==";
    std::cout << abs(diff_x);
    std::cout << "\n";
     std::cout << "diff_y ==";
    std::cout << abs(diff_y);
     std::cout << "\n";


}