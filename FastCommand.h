#pragma once
#include "ICommand.h"

namespace adas {
    class FastCommand : public ICommand {
    public:
        void Execute(PoseHandler& poseHandler) const override {
            poseHandler.FastMode();
        }
    };
}
