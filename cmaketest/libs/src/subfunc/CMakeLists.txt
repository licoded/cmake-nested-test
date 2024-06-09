# 1.将本目录下的所有.c 文件添加到SUB_DIR_LIB_SRCS变量
AUX_SOURCE_DIRECTORY(. SUB_DIR_SRC_LIST)

MESSAGE(STATUS "subfunc层头文件路径 :${SUB_INCLUDE_DIR}")

# 3.生成静态库
add_library(subfunc ${SUB_DIR_SRC_LIST})
# Q: 它并没有依赖subsubfunc中的cpp文件，为什么能正常编译???
#   唯一的解释是，它下面右add_subdirectory(subsubfunc)

# 4.添加subsubfunc子目录，这样子目录中的CMakeLists.txt才会被调用
add_subdirectory(subsubfunc)
# NOTE: 貌似即使这个add_subdirectory命令写在最后，但应该会被最先执行，不然上面使用的${SUB_SUB_INCLUDE_DIR}变量就是空值
