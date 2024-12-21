// FinalExecutorTest.cpp
#include "gtest/gtest.h"
#include "Executor.h"

TEST(ExecutorTest, ReverseCommand) {
    Executor executor({0, 0, 'N'});
    executor.Execute("BM");
    ASSERT_EQ(executor.Query(), Pose{0, -1, 'N'}); // 测试倒车指令
}
