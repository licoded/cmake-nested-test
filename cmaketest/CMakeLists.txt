cmake_minimum_required(VERSION 3.8)     # 1.cmake版本
PROJECT(cmaketest)                      # 2.工程名

# set the project name
set(PROJECT_NAME cmaketest)             # 3.设置工程名

# specify the C++ standard 
set(CMAKE_CXX_STANDARD 17)              # 4.设置c++标准为c++17
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output/bin )   # 配合 add_executable
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output/lib )   # 配合 add_library SHARED
set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output/lib )   # 配合 add_library STATIC

# 5.设置本地头文件路径，注意：子目录中的头文件通过target_include_directories添加到${PROJECT_NAME}中
set(LIBRARY_INCLUDE_PATH ${PROJECT_SOURCE_DIR}/libs/include)

# 9.添加子目录，这样子目录中的CMakeLists.txt才会被调用
add_subdirectory(app)
add_subdirectory(libs)
add_subdirectory(libs/unit-test)
# Q: 凭什么一个与主CMakeLists.txt中的设定一致，一个无关
# Q: 又怎么控制是生成静态库，还是生成新目标？
# Suppose: 都是在子目录的CMakeLists.txt中设置即可
