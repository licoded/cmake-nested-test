# 1.将本目录下的所有.c 文件添加到SUB_DIR_LIB_SRCS变量
AUX_SOURCE_DIRECTORY(. SUB_SUB_DIR_SRC_LIST)

MESSAGE(STATUS "subsubfunc层头文件路径 :${SUB_SUB_INCLUDE_DIR}")

# 3.生成静态库
add_library(subsubfunc ${SUB_SUB_DIR_SRC_LIST})
# Q: 确定最终生成的是静态库，默认不是动态库吗？？？
