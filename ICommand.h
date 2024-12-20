// ICommand.h
#pragma once
#include "PoseHandler.h"

namespace adas {
    class ICommand {
    public:
        virtual ~ICommand() = default;
        virtual void Execute(PoseHandler& poseHandler) const = 0;
    };
}
