#pragma once

#include "maze.h"
#include "agent.h"

enum class MoveDirection { UP, DOWN, LEFT, RIGHT };

class DFSAlgorithm {
public:
    static MoveDirection getNextMove(const Maze& maze, const Agent& agent);

private:
    static bool isValidMove(const Maze& maze, int x, int y);
    static bool dfs(const Maze& maze, int x, int y, int targetX, int targetY, MoveDirection& nextMove);
};
