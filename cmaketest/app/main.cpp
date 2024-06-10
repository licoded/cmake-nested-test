#include <iostream>
#include <string>
#include "func1.h"   //应用层头文件1
#include "func2.h"   //应用层头文件2

int main(int argc, char *argv[])
{
#ifdef DEBUG
    std::cout << "with DEBUG defined" << std::endl;
#endif
    std::cout << "Modified main.cpp" << std::endl;
    func1();  //调用上层func1
    func2();  //调用上层func2
    return 0;
}
