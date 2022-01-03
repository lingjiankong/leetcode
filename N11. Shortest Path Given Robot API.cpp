#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

/*
This interview is focusing on system design/architecture. Try to define everything you need before you start
implementing.

Having a discrete 2D field with some obstacles, and a robot in some initial position.
Your robot has 1 sensor on each side, which tells you if there is an obstacle in this direction.
Robot accepts “move forward”, “turn left” and “turn right” commands.
The robot needs to move into the desired position.
*/

// Note: the answer has not been validated. I think this is correct.
//
// the Robot class is defined by the interviewee.
// This class is helpful to track the robot state (x, y, heading).
struct Robot {
    // assume the following four functions are given.
    bool frontClear();
    bool rightClear();
    bool leftClear();
    bool backClear();

    void moveForward() {
        switch (heading) {
            case 0:
                --x;
                break;
            case 1:
                ++y;
                break;
            case 2:
                ++x;
                break;
            case 3:
                --y;
                break;
        }
    }

    void turnLeft() {
        if (heading == 0) {
            heading = 3;
            return;
        }
        heading--;
    }

    void turnRight() {
        if (heading == 3) {
            heading = 0;
            return;
        }
        heading++;
    };

    string xy() { return to_string(x) + "," + to_string(y); }

    // Current state of the robot.
    int heading;  // 0 up, 1 right, 2 down, 3 left
    int x;
    int y;
};

int shortestPath(Robot& robot, int xGoal, int yGoal) {
    queue<Robot> q;
    q.push(robot);

    unordered_set<string> visited;
    visited.insert(robot.xy());

    int steps = 0;
    while (not q.empty()) {
        int qSize = q.size();
        while (qSize--) {
            Robot curPos = q.front();
            q.pop();

            if (curPos.x == xGoal and curPos.y == yGoal) {
                return steps;
            }

            if (curPos.frontClear()) {
                Robot newPos = curPos;
                newPos.moveForward();
                if (not visited.count(newPos.xy())) {
                    q.push(newPos);
                    visited.insert(newPos.xy());
                }
            }

            if (curPos.rightClear()) {
                Robot newPos = curPos;
                newPos.turnRight();
                newPos.moveForward();
                if (not visited.count(newPos.xy())) {
                    q.push(newPos);
                    visited.insert(newPos.xy());
                }
            }

            if (curPos.backClear()) {
                Robot newPos = curPos;
                newPos.turnRight();
                newPos.turnRight();
                newPos.moveForward();
                if (not visited.count(newPos.xy())) {
                    q.push(newPos);
                    visited.insert(newPos.xy());
                }
            }

            if (curPos.leftClear()) {
                Robot newPos = curPos;
                newPos.turnLeft();
                newPos.moveForward();
                if (not visited.count(newPos.xy())) {
                    q.push(newPos);
                    visited.insert(newPos.xy());
                }
            }
        }
    }

    return -1;
}
