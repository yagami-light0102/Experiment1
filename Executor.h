#pragma once
#include "PoseHandler.h"
#include "ICommand.h"
#include <unordered_map>
#include <string>

namespace adas {
    class Executor {
    public:
        Executor(const Pose& initialPose);
        void Execute(const std::string& command);
        Pose Query() const;

    private:
        PoseHandler poseHandler;
        std::unordered_map<char, std::unique_ptr<ICommand>> commandMap;
        void InitializeCommands();
    };
}
