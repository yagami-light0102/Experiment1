// FinalExecutor.cpp
#include "Executor.h"

void Executor::InitializeCommands() {
    commandMap['M'] = std::make_unique<MoveCommand>();
    commandMap['L'] = std::make_unique<TurnLeftCommand>();
    commandMap['R'] = std::make_unique<TurnRightCommand>();
    commandMap['F'] = std::make_unique<FastCommand>();
    commandMap['B'] = std::make_unique<ReverseCommand>(); // 添加新指令
}

void Executor::Execute(const std::string& command) {
    for (char cmd : command) {
        auto it = commandMap.find(cmd);
        if (it != commandMap.end()) {
            it->second->Execute(poseHandler);
        }
    }
}
