#pragma once

enum class Direction { UP, DOWN, LEFT, RIGHT };

class Agent {
private:
    int x, y;
    Direction direction;

public:
    Agent(int startX, int startY, Direction startDirection);
    int getX() const;
    int getY() const;
    Direction getDirection() const;
    void moveForward();
    void turnLeft();
    void turnRight();
};
