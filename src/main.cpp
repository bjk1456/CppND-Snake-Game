#include "controller.h"
#include "game.h"
#include "renderer.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <string>
#include <thread>
#include <cstring>
#include <bits/stdc++.h>

void getVariablesFromFile(const std::string& filename, std::vector<std::string>& arr) {



          std::ifstream inFile(filename); 
        std::count(std::istreambuf_iterator<char>(inFile), 
             std::istreambuf_iterator<char>(), '\n');
    std::ifstream file(filename);

    if (file.is_open()) {

        std::string line;
        while (std::getline(file, line)) {
                  
        const char* c_line = line.c_str();
        char* nonConstLine = new char[strlen(c_line) + 1];
        strcpy(nonConstLine, c_line);
        char* token = std::strtok(nonConstLine, "=");
        int lineNum = 0;
        int arrayLoc = 0;



        
       
        while (token != nullptr) {
          if(lineNum % 2 == 0){
            std::cout << token << std::endl;
          }
          else{
            std::cout << "ELSE:" << std::endl;
            std::string value(token);
            arr.push_back(value);
            std::cout << value << std::endl;
          }
        token = std::strtok(nullptr, "="); 
        lineNum += 1;
         
        

    }
            //std::cout << line << std::endl;
        }
        file.close();
    } else {
        std::cerr << "There was an opening opening the file." << filename << std::endl;
    }
}

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};
  

    std::vector<std::string> userVars;
    std::string filename = "SnakeVars.txt";

    // Create a thread to process the file
    std::thread fileThread(getVariablesFromFile, filename, std::ref(userVars));

    // Do other work in the main thread...

    // Wait for the file processing thread to finish
    fileThread.join();
  
  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
  Game game(kGridWidth, kGridHeight, userVars);
  game.Run(controller, renderer, kMsPerFrame);
  std::cout << "Game has terminated successfully!\n";
  std::cout << "Score: " << game.GetScore() << "\n";
  std::cout << "Size: " << game.GetSize() << "\n";
  return 0;
}