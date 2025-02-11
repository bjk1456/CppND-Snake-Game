#include "cobra.h"
#include "controller.h"
#include <iostream>
#include <cmath>


void Cobra::GrowBody() { 
    std::cout << "Cobra::GetGrowing()"  << std::endl;
    std::cout << Cobra::GetGrowing()  << std::endl;
    std::cout << userVarCobraGrowing  << std::endl;

    growing =  Cobra::GetGrowing(); 

    }

bool Cobra::GetGrowing(){
    return userVarCobraGrowing;
}

void Cobra::setFoodLoc(SDL_Point food) {
    the_food = food;
}

void Cobra::FindClosestNode() {
    int cast_x = static_cast<int>(head_x);
    int cast_y = static_cast<int>(head_y);

    int diff_x = static_cast<int>(head_x) - the_food.x;
    int diff_y = static_cast<int>(head_y) - the_food.y;
}