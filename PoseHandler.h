// PoseHandler.h
#pragma once
#include "Pose.h"

namespace adas {
    class PoseHandler {
    public:
        PoseHandler(const Pose& initialPose);
        void Move();
        void TurnLeft();
        void TurnRight();
        Pose GetPose() const;

    private:
        Pose pose;
    };
}
