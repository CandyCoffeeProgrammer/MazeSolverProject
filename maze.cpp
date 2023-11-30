#include "maze.h"

Maze::Maze(const std::string& filename)
    : agentRow(-1), agentCol(-1), direction(0), speedPotions(0), goggles(1), fog(0), slowpokePotions(0), stepsTaken(0) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Failed to open the maze file." << std::endl;
        exit(1);
    }

    std::string line;
    size_t maxRowWidth = 0; // Track the maximum row width

    while (std::getline(file, line)) {
        std::vector<int> row;

        for (char c : line) {
            switch (c) {
            case '1':
                row.push_back(1); // Wall
                break;
            case '0':
                row.push_back(0); // Empty space
                break;
            case '2':
                row.push_back(2); // Starting point
                startRow = mazeData.size();
                startCol = row.size();
                agentRow = startRow;
                agentCol = startCol;
                break;
            case '3':
                row.push_back(3); // Ending point
                exitRow = mazeData.size();
                exitCol = row.size();
                break;
            case '4':
                row.push_back(4); // Googles
                break;
            case '5':
                row.push_back(5); // Speed potion
                break;
            case '6':
                row.push_back(6); // Fog
                break;
            case '7':
                row.push_back(7); // Slowpoke potion
                break;
            default:
                row.push_back(0); // Default to empty space
                break;
            }
        }

        // Ensure all rows have the same width by padding with walls if needed
        while (row.size() < maxRowWidth) {
            row.push_back(1); // Pad with walls
        }

        mazeData.push_back(row);

        // Update the maximum row width
        maxRowWidth = std::max(maxRowWidth, row.size());
    }

    file.close();
}



void Maze::displayMaze() {
    for (int i = 0; i < mazeData.size(); i++) {
        for (int j = 0; j < mazeData[i].size(); j++) {
            if (i == agentRow && j == agentCol) {
                std::cout << 'A'; // Display the agent
            }
            else {
                switch (mazeData[i][j]) {
                case 1:
                    std::cout << '#'; // Wall
                    break;
                case 0:
                    std::cout << ' '; // Empty
                    break;
                case 2:
                    std::cout << 'S'; // Starting point
                    break;
                case 3:
                    std::cout << 'E'; // Ending point
                    break;
                case 4:
                    std::cout << 'G'; // Goggles
                    break;
                case 5:
                    std::cout << 'P'; // Speed potion
                    break;
                case 6:
                    std::cout << 'F'; // Fog
                    break;
                case 7:
                    std::cout << '7'; // Slowpoke potion
                    break;
                }
            }
        }
        std::cout << std::endl;
    }
}

bool Maze::isWall(int row, int col) {
    return mazeData[row][col] == 1;
}

void Maze::moveAgent() {
    int stepWidth = 1 + speedPotions - slowpokePotions;
    stepWidth = std::max(1, std::min(stepWidth, 3)); // Ensure stepWidth is between 1 and 3

    int perceptiveField = 1 + goggles - fog;
    perceptiveField = std::max(1, perceptiveField); // Ensure perceptiveField is at least 1

    int newCol = agentCol;
    int newRow = agentRow;

    if (direction == 0) {
        newCol += stepWidth;
    }
    else if (direction == 1) {
        newRow += stepWidth;
    }
    else if (direction == 2) {
        newCol -= stepWidth;
    }
    else if (direction == 3) {
        newRow -= stepWidth;
    }

    if (newRow >= 0 && newRow < mazeData.size() && newCol >= 0 && newCol < mazeData[0].size()) {
        int targetCell = mazeData[newRow][newCol];
        int currentCell = mazeData[agentRow][agentCol];

        if (currentCell == 1 || targetCell == 1) {
            // The agent is on or moving into a wall, do not move
            return;
        }

        if (targetCell == 2) {
            // Starting point
            // Update the agent's position
            agentRow = newRow;
            agentCol = newCol;
        }
        else if (targetCell == 3) {
            // Ending point (exit), end the game and print the step count
            std::cout << "Congratulations! You reached the end of the maze." << std::endl;
            std::cout << "Steps taken: " << (stepsTaken + 1) << std::endl;
            exit(0); // End the game
        }
        else if (targetCell == 0) {
            // Empty space, update the agent's position
            agentRow = newRow;
            agentCol = newCol;
        }
        else {
            // Remove boosters (4: Goggles, 5: Speed potion, 6: Fog, 7: Slowpoke potion)
            mazeData[newRow][newCol] = 0;
            agentRow = newRow;
            agentCol = newCol;
        }

        stepsTaken++; // Increment the steps taken when the agent moves
    }
}

void Maze::turnRight() {
    direction = (direction + 1) % 4; // Right turn (clockwise)
}

void Maze::turnLeft() {
    direction = (direction + 3) % 4; // Left turn (counterclockwise)
}

int Maze::getStepsTaken() const {
    return stepsTaken;
}