#include <iostream>
#include <string>
#include <vector>

class Executor {
	private:
		bool isFast = false; // 标记是否处于加速状态
		int poseX = 0, poseY = 0; // 当前位置
		char poseHeading = 'N'; // 当前朝向，N(北), E(东), S(南), W(西)

	public:
		void execute(const std::string &command) {
			if (command == "F") {
				isFast = !isFast; // 切换加速状态
				std::cout << "Acceleration " << (isFast ? "enabled" : "disabled") << std::endl;
			} else if (isFast) {
				handleFastCommand(command);
			} else {
				handleNormalCommand(command);
			}
		}

	private:
		void handleFastCommand(const std::string &command) {
			switch (command[0]) {
				case 'M':
					move('M');
					break;
				case 'L':
					move('M');
					turnLeft();
					break;
				case 'R':
					move('M');
					turnRight();
					break;
			}
		}

		void handleNormalCommand(const std::string &command) {
		}

		void move(char direction) {
			switch (direction) {
				case 'M':
					if (poseHeading == 'N')
						poseY++; // 向北移动，Y坐标增加
					else if (poseHeading == 'S')
						poseY--; // 向南移动，Y坐标减少
					else if (poseHeading == 'E')
						poseX++; // 向东移动，X坐标增加
					else if (poseHeading == 'W')
						poseX--; // 向西移动，X坐标减少
					break;
			}
		}

		void turnLeft() {
			poseHeading = (poseHeading == 'N') ? 'W' : (poseHeading == 'W') ? 'S' : (poseHeading == 'S') ? 'E' : 'N';
			// 左转：北->西，西->南，南->东，东->北
		}

		void turnRight() {
			poseHeading = (poseHeading == 'N') ? 'E' : (poseHeading == 'E') ? 'S' : (poseHeading == 'S') ? 'W' : 'N';
			// 右转：北->东，东->南，南->西，西->北
		}
};

int main() {
	Executor executor;
	std::vector<std::string> commands = {"F", "M", "L", "R", "F"};
	for (const auto &cmd : commands) {
		executor.execute(cmd);
	}
	return 0;
}
