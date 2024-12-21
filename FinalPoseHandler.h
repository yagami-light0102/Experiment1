// FinalPoseHandler.h
#pragma once
#include "Pose.h"

namespace adas {
    class PoseHandler {
    public:
        PoseHandler(const Pose& initialPose);
        void Move();
        void TurnLeft();
        void TurnRight();
        void Reverse(); // 新增方法处理倒车
        Pose GetPose() const;

    private:
        Pose pose;
        bool isReverse = false; // 新增成员变量标记倒车状态
    };
}
