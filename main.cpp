#include "Executor.h" // 包含Executor类的定义
#include <cassert>    // 包含断言功能，用于测试
 
// 定义一个测试函数，用于测试Executor的移动功能
void TestExecutorMovement() {
    // 创建一个Executor对象，初始位置为(0, 0)，方向为'N'（北）
    Executor executor({0, 0, 'N'});
    
    // 执行一系列移动指令："MLMMRM"
    // M表示移动，L表示左转，R表示右转
    executor.Execute("MLMMRM");
    
    // 预期执行完指令后的姿态为：位置(-2, 2)，方向仍为'N'
    Pose expectedPose = {-2, 2, 'N'};
    
    // 使用断言来验证Executor对象的当前姿态是否与预期一致
    // 如果不一致，程序将在这里终止（如果断言被启用）
    assert(executor.Query() == expectedPose);
}
 
// 主函数
int main() {
    // 调用测试函数
    TestExecutorMovement();
    
    // 如果测试通过（即没有触发断言失败），则打印消息
    std::cout << "Movement test passed." << std::endl;
    
    // 返回0，表示程序正常结束
    return 0;
}
