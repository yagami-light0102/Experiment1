#include <iostream>
#include <unordered_map>
#include <memory>
#include <string>

// 定义机器人的位置和朝向
struct Pose {
	int x, y; // 坐标位置
	char heading; // 朝向，'N', 'S', 'E', 'W' 分别代表北、南、东、西
	Pose(int x = 0, int y = 0, char heading = 'N') : x(x), y(y), heading(heading) {}
	bool operator==(const Pose &other) const {
		return x == other.x && y == other.y && heading == other.heading;
	}
};

// 命令接口，所有命令类将实现这个接口
class ICommand {
	public:
		virtual ~ICommand() {}
		virtual void Execute(Pose &pose) = 0; // 执行命令，修改pose状态
};

// 实现向前移动的命令
class MoveCommand : public ICommand {
	public:
		void Execute(Pose &pose) override {
			switch (pose.heading) {
				case 'N':
					++pose.y;
					break; // 向北移动，y坐标增加
				case 'S':
					--pose.y;
					break; // 向南移动，y坐标减少
				case 'E':
					++pose.x;
					break; // 向东移动，x坐标增加
				case 'W':
					--pose.x;
					break; // 向西移动，x坐标减少
			}
		}
};

// 实现向左转的命令
class TurnLeftCommand : public ICommand {
	public:
		void Execute(Pose &pose) override {
			pose.heading = (pose.heading == 'N') ? 'W' :
			               (pose.heading == 'W') ? 'S' :
			               (pose.heading == 'S') ? 'E' : 'N'; // 左转90度
		}
};

// 实现向右转的命令
class TurnRightCommand : public ICommand {
	public:
		void Execute(Pose &pose) override {
			pose.heading = (pose.heading == 'N') ? 'E' :
			               (pose.heading == 'E') ? 'S' :
			               (pose.heading == 'S') ? 'W' : 'N'; // 右转90度
		}
};

// 实现快速移动的命令，这里简单地连续执行两次MoveCommand
class FastCommand : public ICommand {
	public:
		void Execute(Pose &pose) override {
			for (int i = 0; i < 2; ++i) {
				MoveCommand().Execute(pose); // 快速模式下，连续移动两格
			}
		}
};

// 实现反转方向的命令
class ReverseCommand : public ICommand {
	public:
		void Execute(Pose &pose) override {
			pose.x = -pose.x; // x坐标取反
			pose.y = -pose.y; // y坐标取反
			pose.heading = (pose.heading == 'N') ? 'S' :
			               (pose.heading == 'S') ? 'N' :
			               (pose.heading == 'E') ? 'W' : 'E'; // 朝向取反
		}
};

// 执行器类，用于执行一系列命令
class Executor {
	public:
		Executor(const Pose &initialPose) : pose(initialPose) { // 初始化执行器和pose
			InitializeCommands();
		}
		void Execute(const std::string &command) { // 执行一系列命令
			for (char cmd : command) {
				auto it = commandMap.find(cmd);
				if (it != commandMap.end()) {
					it->second->Execute(pose); // 执行找到的命令
				}
			}
		}
		Pose Query() const { // 查询当前pose状态
			return pose;
		}

	private:
		Pose pose; // 当前pose状态
		std::unordered_map<char, std::unique_ptr<ICommand>> commandMap; // 命令映射表
		void InitializeCommands() { // 初始化命令映射表
			commandMap['M'] = std::make_unique<MoveCommand>();
			commandMap['L'] = std::make_unique<TurnLeftCommand>();
			commandMap['R'] = std::make_unique<TurnRightCommand>();
			commandMap['F'] = std::make_unique<FastCommand>();
			commandMap['B'] = std::make_unique<ReverseCommand>();
		}
};

// 测试Executor类的功能
void TestExecutor() {
	Executor executor({0, 0, 'N'}); // 初始化Executor和pose

	// 测试向前移动
	executor.Execute("M");
	if (executor.Query() == Pose{0, 1, 'N'}) {
		std::cout << "Test 1 passed: Move forward\n";
	} else {
		std::cout << "Test 1 failed: Move forward\n";
	}

	// 测试向左转
	executor.Execute("L");
	if (executor.Query() == Pose{0, 1, 'W'}) {
		std::cout << "Test 2 passed: Turn left\n";
	} else {
		std::cout << "Test 2 failed: Turn left\n";
	}

	// 测试反转方向
	executor.Execute("B");
	if (executor.Query() == Pose{0, -1, 'E'}) {
		std::cout << "Test 3 passed: Reverse\n";
	} else {
		std::cout << "Test 3 failed: Reverse\n";
	}
}

int main() {
	TestExecutor(); // 运行测试
	return 0;
}
