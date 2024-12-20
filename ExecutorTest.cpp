// ExecutorTest.cpp
#include "gtest/gtest.h"
#include "Executor.h"

TEST(ExecutorTest, ExecutesFastMode) {
    Executor executor({0, 0, 'N'});
    executor.Execute("FF");
    ASSERT_EQ(executor.Query(), Pose{0, 2, 'N'});  // 快速模式下，北向移动两步
}
