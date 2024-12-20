// MoveCommand.h
#pragma once
#include "ICommand.h"

namespace adas {
    class MoveCommand : public ICommand {
    public:
        void Execute(PoseHandler& poseHandler) const override {
            poseHandler.Move();
        }
    };
}
