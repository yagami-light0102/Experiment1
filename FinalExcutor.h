// 执行器.h
#pragma一次
#include “PoseHandler.h”
#include“ICommand.h”
#include  <无序映射>
#include <字符串>
#include  <内存>

命名空间 adas {
    类执行器{
    孙：
        执行器(常量姿势&初始姿势) ;
        void 执行( const std::string& 命令) ;
        姿势查询( ) 常量；

    私人的：
        PoseHandler姿势处理程序；
        std::unordered_map< char, std::unique_ptr < ICommand >> commandMap;
        无效初始化命令（）；
    } ;
}
