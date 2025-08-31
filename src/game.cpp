#include "game.h"
#include <iostream>
#include "SDL.h"
#include <mutex>
#include <fstream>
#include <string>
#include <thread>

std::ofstream log_file("snake_score.txt");
std::mutex file_mutex;

Game::Game(std::size_t grid_width, std::size_t grid_height, bool userVarCobraGrowing)
    : garter(grid_width, grid_height),
      cobra(grid_width - 1, grid_height - 1, userVarCobraGrowing),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width - 1)),
      random_h(0, static_cast<int>(grid_height - 1)) {
  PlaceFood();
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    //controller.HandleInput(running, garter, cobra);
    controller.HandleInput(running, garter, cobra);
    //controller.HandlePredatorInput(running, cobra);
    Update();
    renderer.Render(garter, cobra, food);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

void Game::PlaceFood() {
  int x, y;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a garter item before placing
    // food.
    if (!garter.SnakeCell(x, y)) {
      food.x = x;
      food.y = y;
      cobra.setFoodLoc(food);
      return;
    }
  }
}

void Game::write_score_log(const std::string& message) {
    std::lock_guard<std::mutex> lock(file_mutex); // Acquire lock
    log_file << message << std::endl;
}

void Game::write_function(int score) {
    Game::write_score_log("The final score for the garter snake is " + std::to_string(score));
}

void Game::Update() {

  if (!garter.alive) {
    std::thread t1(Game::write_function, score);
    t1.join();

    log_file.close();
    return;
  }

  garter.Update();

  int new_x = static_cast<int>(garter.head_x);
  int new_y = static_cast<int>(garter.head_y);
  
  // Check if there's food over here
  if (food.x == new_x && food.y == new_y) {
    score++;
    PlaceFood();
    // Grow garter and increase speed.
    garter.GrowBody();
    garter.speed += 0.02;
  }

  if (!cobra.alive) return;

  cobra.Update();

  int new_x_c= static_cast<int>(cobra.head_x);
  int new_y_c = static_cast<int>(cobra.head_y);

  // Check if there's food over here
  if (food.x == new_x_c && food.y == new_y_c) {
    score++;
    PlaceFood();
    // Grow garter and increase speed.
    cobra.GrowBody();
    cobra.speed += 0.02;
  }
}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return garter.size; }