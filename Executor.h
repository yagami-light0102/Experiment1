#pragma once
#include "Pose.h"

class Executor {
public:
    Executor(const Pose& initialPose);
    void Execute(const std::string& command);
    Pose Query() const;

private:
    Pose pose;
    void Move();
    void TurnLeft();
    void TurnRight();
};
