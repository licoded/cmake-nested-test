INCLUDE_DIRECTORIES( ${LIBRARY_INCLUDE_PATH} )

# 1.将本目录下的所有.c 文件添加到SUB_DIR_LIB_SRCS变量
UNSET(SUB_DIR_SRC_LIST)
AUX_SOURCE_DIRECTORY(. SUB_DIR_SRC_LIST)

MESSAGE("SUB_DIR_SRC_LIST in src ROOT :${SUB_DIR_SRC_LIST}")

# 3.生成静态库
add_library(two_func ${SUB_DIR_SRC_LIST})

# 4.添加subsubfunc子目录，这样子目录中的CMakeLists.txt才会被调用
add_subdirectory(subfunc)
