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
#include <string>

void getVariablesFromFile(const std::string& filename, bool &userVarCobraGrowing) {



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
        std::string s_true = "true";
        std::string s_CobraGrowing = "CobraGrowing";
        int lineNum = 0;
        int arrayLoc = 0;       
       
        while (token != nullptr) {
          if (strcmp(token, s_CobraGrowing.c_str()) == 0) {
              std::cout << token << std::endl;
              std::cout << "ITS A HIT!!!!!!!!!!!!!!:" << std::endl;
              //std::cout << "userVarCobraGrowing" << std::endl;
              //std::cout << userVarCobraGrowing << std::endl;
              token = std::strtok(nullptr, "=");
              std::cout << "new token is " << std::endl;
              std::cout << token << std::endl;
              if (strcmp(token, s_true.c_str()) == 0) {
                  userVarCobraGrowing = true;
                  std::cout << "userVarCobraGrowing" << std::endl;
                  std::cout << userVarCobraGrowing << std::endl;
              }
              std::cout << token << std::endl;
          }
          
          if(lineNum % 2 == 0){
            std::cout << token << std::endl;
          }
          else{
            std::cout << "ELSE:" << std::endl;
            std::string value(token);
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
  

    bool userVarCobraGrowing = false;
    std::string filename = "SnakeVars.txt";

    // Create a thread to process the file
    std::thread fileThread(getVariablesFromFile, filename, std::ref(userVarCobraGrowing));

    // Do other work in the main thread...

    // Wait for the file processing thread to finish
    fileThread.join();
  
  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
  Game game(kGridWidth, kGridHeight, userVarCobraGrowing);
  game.Run(controller, renderer, kMsPerFrame);
  return 0;
}