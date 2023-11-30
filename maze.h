#pragma once

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
    int getStepsTaken() const;
    const std::vector<std::vector<int>>& getMazeData() const {
        return mazeData;
    }

private:
    std::vector<std::vector<int>> mazeData;
    int startRow, startCol;
    int exitRow, exitCol;
    int agentRow, agentCol;
    int direction;
    int speedPotions;
    int goggles;
    int fog;
    int slowpokePotions;
    int stepsTaken;

    bool isWall(int row, int col);
    void encounterBooster(int boosterType);
};
