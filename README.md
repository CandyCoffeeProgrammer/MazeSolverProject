# MazeSolverProject

Maze Solver GUI
This project is an interactive maze-solving application with a depth first search algorithm. The maze-solving agent navigates through a maze from the starting point to the endpoint while encountering boosters and hurdles. The game allows users to control the agent's movements, and the agent can autonomously navigate the maze using a depth-first search algorithm.

Features

Maze Generation: The maze is loaded from a file, and the program displays the starting point (S), endpoint (E), walls (#), boosters (Goggles, Speed Potion), and hurdles (Fog, Slowpoke Potion).

Agent Movements: Users can control the agent's movements using arrow keys (up, down, left, right). The agent can also autonomously navigate the maze using a depth-first search algorithm.

Boosters and Hurdles: Boosters and hurdles alter the agent's behavior. Goggles increase the perceptive field, speed potions increase step width, fog reduces perceptive field, and slowpoke potions decrease step width.

Scoring: The program keeps track of the steps taken to reach the goal or return to the starting position if the endpoint is unreachable.

How to Use
Build the Project:

Clone the repository.
Build the project using CMake.
Run the Application:

Execute the compiled executable.
Follow the on-screen instructions.
Control the Agent:

Use arrow keys to move the agent.
Press 'R' to turn right, 'L' to turn left, 'M' to move forward.
Press 'Q' to quit the game.
Autonomous Mode:

The agent can autonomously navigate using the depth-first search algorithm. Observe the agent's movements.
Requirements
C++ Compiler
CMake
Project Structure
lua
Copy code
project/
|-- include/
|   |-- maze.h
|   |-- agent.h
|   |-- DFSAlgorithm.h
|-- src/
|   |-- maze.cpp
|   |-- agent.cpp
|   |-- DFSAlgorithm.cpp
|   |-- main.cpp
|-- resources/
|   |-- maze.txt
|-- CMakeLists.txt
|-- build/
Credits
This project was created by Renato Mutavdzic. Feel free to contribute or report issues.