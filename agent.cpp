#include "Agent.h"

Agent::Agent(int startX, int startY, Direction startDirection)
    : x(startX), y(startY), direction(startDirection) {
    // Constructor implementation
}

//getting position X and Y of agent
int Agent::getX() const {
    return x;
}

int Agent::getY() const {
    return y;
}

//getting direction of agent
Direction Agent::getDirection() const {
    return direction;
}

// movement of agent
void Agent::moveForward() {
    switch (direction) {
    case Direction::UP:
        y--;
        break;
    case Direction::DOWN:
        y++;
        break;
    case Direction::LEFT:
        x--;
        break;
    case Direction::RIGHT:
        x++;
        break;
    }
}

void Agent::turnLeft() {
    switch (direction) {
    case Direction::UP:
        direction = Direction::LEFT;
        break;
    case Direction::DOWN:
        direction = Direction::RIGHT;
        break;
    case Direction::LEFT:
        direction = Direction::DOWN;
        break;
    case Direction::RIGHT:
        direction = Direction::UP;
        break;
    }
}

void Agent::turnRight() {
    switch (direction) {
    case Direction::UP:
        direction = Direction::RIGHT;
        break;
    case Direction::DOWN:
        direction = Direction::LEFT;
        break;
    case Direction::LEFT:
        direction = Direction::UP;
        break;
    case Direction::RIGHT:
        direction = Direction::DOWN;
        break;
    }
}
