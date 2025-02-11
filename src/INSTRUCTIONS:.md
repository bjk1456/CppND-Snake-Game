INSTRUCTIONS:
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
