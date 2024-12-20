// main.cpp
// 引入Executor.h头文件，这样我们可以使用Executor类和Pose结构体。
#include "Executor.h"
// 引入iostream库，用于输入输出操作。
#include <iostream>
// 引入cassert库，用于断言测试，确保程序逻辑正确。
#include <cassert>

// 重载==运算符，用于比较两个Pose对象是否在位置和朝向上完全相同。
bool operator==(const Pose& lhs, const Pose& rhs) {
    return lhs.x == rhs.x && lhs.y == rhs.y && lhs.heading == rhs.heading;
}

// 定义一个测试函数，用于测试Executor类的移动逻辑是否正确。
void TestExecutorMovement() {
    // 创建一个Executor对象，初始位置在原点(0, 0)，朝向北'N'。
    Executor executor({0, 0, 'N'});
    // 执行一系列移动和转向指令：前进，左转，前进，前进，右转，前进。
    executor.Execute("MLMMRM");
    // 定义预期的最终位置和朝向，根据指令序列，预期位置应为(-2, 2)，朝向北'N'。
    Pose expectedPose = {-2, 2, 'N'};
    // 使用assert宏来断言实际的最终位置和朝向是否与预期相符。
    // 如果不相符，程序将终止并给出错误信息。
    assert(executor.Query() == expectedPose);
}

// 程序的入口点。
int main() {
    // 调用测试函数，执行测试。
    TestExecutorMovement();
    // 如果测试没有导致程序终止，说明测试通过，输出成功信息。
    std::cout << "Movement test passed." << std::endl;
    // 返回0表示程序成功执行完毕。
    return 0;
}
