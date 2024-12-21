// ReverseCommand.h
#pragma once
#include "ICommand.h"

namespace adas {
    class ReverseCommand : public ICommand {
    public:
        void Execute(PoseHandler& poseHandler) const override {
            poseHandler.Reverse();
        }
    };
}
