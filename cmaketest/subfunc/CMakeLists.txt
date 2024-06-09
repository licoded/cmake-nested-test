# 1.将本目录下的所有.c 文件添加到SUB_DIR_LIB_SRCS变量
AUX_SOURCE_DIRECTORY(. SUB_DIR_SRC_LIST)

# 2.设置当前的头文件路径
set(SUB_INCLUDE_DIR 
    ${CMAKE_CURRENT_SOURCE_DIR}          # 当前源文件路径 -- 即CMakeLists.txt文件所处的文件夹路径
    ${SUB_SUB_INCLUDE_DIR}               # 由下层subsubfunc目录传递的头文件路径
    CACHE INTERNAL "subfunc include dir" # 这个字符串相当于对变量SUB_INCLUDE_DIR的描述说明，不能省略，但可以自己随便定义,只有添加了这个描述SUB_INCLUDE_DIR变量才能被上层CMakeLists.txt调用！！！
)

MESSAGE(STATUS "subfunc层头文件路径 :${SUB_INCLUDE_DIR}")

# 3.生成静态库
add_library(subfunc ${SUB_DIR_SRC_LIST})
# Q: 它并没有依赖subsubfunc中的cpp文件，为什么能正常编译???
#   唯一的解释是，它下面右add_subdirectory(subsubfunc)

# 4.添加subsubfunc子目录，这样子目录中的CMakeLists.txt才会被调用
add_subdirectory(subsubfunc)
# NOTE: 貌似即使这个add_subdirectory命令写在最后，但应该会被最先执行，不然上面使用的${SUB_SUB_INCLUDE_DIR}变量就是空值
