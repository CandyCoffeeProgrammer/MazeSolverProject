#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Maze {
public:
    Maze(const std::string& filename);
    void displayMaze();
    void moveAgent();
    void turnRight();
    void turnLeft();
    int getStepsTaken() const; // Function to get the steps taken

private:
    std::vector<std::vector<int>> mazeData;
    int startRow, startCol;
    int exitRow, exitCol;
    int agentRow, agentCol;
    int direction; // 0: right, 1: down, 2: left, 3: up
    int speedPotions;
    int goggles;
    int fog;
    int slowpokePotions;
    int stepsTaken; // Variable to track steps taken

    bool isWall(int row, int col);
};

Maze::Maze(const std::string& filename)
    : agentRow(-1), agentCol(-1), direction(0), speedPotions(0), goggles(1), fog(0), slowpokePotions(0), stepsTaken(0) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Failed to open the maze file." << std::endl;
        exit(1);
    }

    std::string line;
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
        mazeData.push_back(row);
    }
    file.close();
}

void Maze::displayMaze() {
    for (const auto& row : mazeData) {
        for (int cell : row) {
            switch (cell) {
            case 1:
                std::cout << '#'; // Wall
                break;
            case 0:
                std::cout << ' '; // Empty space
                break;
            case 2:
                std::cout << 'S'; // Starting point
                break;
            case 3:
                std::cout << 'E'; // Ending point
                break;
            case 4:
                std::cout << 'G'; // Googles
                break;
            case 5:
                std::cout << 'P'; // Speed potion
                break;
            case 6:
                std::cout << 'F'; // Fog
                break;
            case 7:
                std::cout << 'SP'; // Slowpoke potion
                break;
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

    if (newRow >= 0 && newRow < mazeData.size() && newCol >= 0 && newCol < mazeData[0].size() && !isWall(newRow, newCol)) {
        agentRow = newRow;
        agentCol = newCol;
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

int main() {
    Maze maze("maze.txt");

    // Display the maze to see the agent's position and orientation
    maze.displayMaze();

    // Get the steps taken
    int steps = maze.getStepsTaken();
    std::cout << "Steps taken: " << steps << std::endl;

    return 0;
}
