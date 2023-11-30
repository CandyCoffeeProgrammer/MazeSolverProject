#include "algorithm.h"

MoveDirection DFSAlgorithm::getNextMove(const Maze& maze, const Agent& agent) {
    int currentX = agent.getX();
    int currentY = agent.getY();

    // Specify the target coordinates based on the current direction
    int targetX = currentX;
    int targetY = currentY;

    switch (agent.getDirection()) {
    case Direction::UP:
        targetY--;
        break;
    case Direction::DOWN:
        targetY++;
        break;
    case Direction::LEFT:
        targetX--;
        break;
    case Direction::RIGHT:
        targetX++;
        break;
    }

    MoveDirection nextMove = MoveDirection::UP; // Default to UP if DFS fails

    if (dfs(maze, currentX, currentY, targetX, targetY, nextMove)) {
        return nextMove;
    }

    return MoveDirection::UP; // Default to UP if DFS fails
}

bool DFSAlgorithm::isValidMove(const Maze& maze, int x, int y) {
    // Check if the move is within the maze boundaries and not a wall
    return x >= 0 && x < static_cast<int>(maze.getMazeData().size()) &&
        y >= 0 && y < static_cast<int>(maze.getMazeData()[0].size()) &&
        maze.getMazeData()[x][y] != 1;
}

bool DFSAlgorithm::dfs(const Maze& maze, int x, int y, int targetX, int targetY, MoveDirection& nextMove) {
    // Base case: reached the target coordinates
    if (x == targetX && y == targetY) {
        return true;
    }

    // Possible moves (UP, DOWN, LEFT, RIGHT)
    int dx[] = { 0, 0, -1, 1 };
    int dy[] = { -1, 1, 0, 0 };

    for (int i = 0; i < 4; ++i) {
        int newX = x + dx[i];
        int newY = y + dy[i];

        // Check if the new move is valid
        if (isValidMove(maze, newX, newY)) {
            // Explore the next move recursively
            if (dfs(maze, newX, newY, targetX, targetY, nextMove)) {
                // Update the nextMove based on the current move
                if (i == 0) {
                    nextMove = MoveDirection::UP;
                }
                else if (i == 1) {
                    nextMove = MoveDirection::DOWN;
                }
                else if (i == 2) {
                    nextMove = MoveDirection::LEFT;
                }
                else if (i == 3) {
                    nextMove = MoveDirection::RIGHT;
                }

                return true;
            }
        }
    }

    return false;
}
