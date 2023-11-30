#include "maze.h"
#include "agent.h"

int main() {
    Maze maze("maze.txt");

    // Display the initial maze state
    maze.displayMaze();

    // Get user input to control the agent's movements
    while (true) {
        std::cout << "Enter a command (M for Move, R for Turn Right, L for Turn Left, Q to Quit): ";
        char command;
        std::cin >> command;

        if (command == 'Q' || command == 'q') {
            break;  // Exit the loop if the user quits
        }

        if (command == 'M' || command == 'm') {
            // Move the agent
            maze.moveAgent();
        }
        else if (command == 'R' || command == 'r') {
            // Turn the agent right
            maze.turnRight();
        }
        else if (command == 'L' || command == 'l') {
            // Turn the agent left
            maze.turnLeft();
        }

        system("cls");

        // Display the updated maze state with the agent's new position
        maze.displayMaze();
    }

    // Get the steps taken
    int steps = maze.getStepsTaken();
    std::cout << "Steps taken: " << steps << std::endl;

    return 0;
}