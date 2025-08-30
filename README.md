# CPPND: Capstone Snake Game Example

This is a starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

The Capstone Project gives you a chance to integrate what you've learned throughout this program. This project will become an important part of your portfolio to share with current and future colleagues and employers.

In this project, you can build your own C++ application or extend this Snake game, following the principles you have learned throughout this Nanodegree Program. This project will demonstrate that you can independently create applications using a wide range of C++ features.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.


## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg

## INSTRUCTIONS:
Enter the build directory and build the SnakeGame executable by running `cmake .. && make`.Run the SnakeGame executable by running `./SnakeGame`

New Features:
There are now 2 snakes - Garter and Cobra. The Garter is controlled by the user just as before. The Cobra is a competitor that runs on the A* algorithm to find the apple. Everytime a user makes a move the Cobra moves to the neighbor square closest to the apple. If the Cobra makes contact with the apple then the round concludes.

Each Rubric Point addressed:
*Loops, Functions, I/O:
1) The project reads data from SnakeVars.txt and sets variables arrording to the values set there - e.g. whether or not Cobra expands after eating the apple.
2) The project accepts user input and uses it to determine when the Cobra snake will change direction.

*Object Oriented Programming:
1) The Cobra and Garter classes are added to the project. Both inherit functionality from the Snake class.
2) The Cobra and Garter classes follow inheritance hierarchy with the Cobra overriding the ability to grow and the color of its head.
3) The Cobra class abstracts the way it moves - using the A* algorithm - from its interface.

*Memory Management:
1) Inside the Controller class both the HandlePredatorInput and ChangeDirection methods use pass-by-reference.
2) The Cobra class uses a destructor
3) Rhe CObra class utilizes a move constructor

*Concurrency
1) Multithreading is used to read the properties file.
2) A promise and future is used in main.cpp for the variables exisiting in the properties file.