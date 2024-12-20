// Executor.cpp
#include "Executor.h"

// Executor类的构造函数，接收一个Pose对象作为初始位置，并将其赋值给成员变量pose。
Executor::Executor(const Pose& initialPose) : pose(initialPose) {}

// 执行传入的命令字符串
void Executor::Execute(const std::string& command) {
    // 遍历命令字符串中的每个字符
    for (char cmd : command) {
        // 根据字符执行相应的动作
        if (cmd == 'M') Move();       // 如果字符是'M'，则调用Move函数
        else if (cmd == 'L') TurnLeft(); // 如果字符是'L'，则调用TurnLeft函数
        else if (cmd == 'R') TurnRight(); // 如果字符是'R'，则调用TurnRight函数
    }
}

// 查询当前的位置和朝向
Pose Executor::Query() const {
    return pose; // 返回当前的pose对象
}

// 移动函数，根据当前的朝向增加或减少x或y坐标
void Executor::Move() {
    switch (pose.heading) {
    case 'N': ++pose.y; break; // 如果朝向是北（'N'），则y坐标增加
    case 'S': --pose.y; break; // 如果朝向是南（'S'），则y坐标减少
    case 'E': ++pose.x; break; // 如果朝向是东（'E'），则x坐标增加
    case 'W': --pose.x; break; // 如果朝向是西（'W'），则x坐标减少
    }
}

// 向左转函数，改变朝向
void Executor::TurnLeft() {
    // 根据当前的朝向，计算左转后的新朝向
    pose.heading = (pose.heading == 'N') ? 'W' : // 北转西
                    (pose.heading == 'W') ? 'S' : // 西转南
                    (pose.heading == 'S') ? 'E' : 'N'; // 南转东，东转北
}

// 向右转函数，改变朝向
void Executor::TurnRight() {
    // 根据当前的朝向，计算右转后的新朝向
    pose.heading = (pose.heading == 'N') ? 'E' : // 北转东
                    (pose.heading == 'E') ? 'S' : // 东转南
                    (pose.heading == 'S') ? 'W' : 'N'; // 南转西，西转北
}