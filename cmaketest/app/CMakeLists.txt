set (APP_NAME "ltlfsyn-bin")

INCLUDE_DIRECTORIES( ${LIBRARY_INCLUDE_PATH} )

# 6.将源文件路径添加到变量SRC_LIST中
AUX_SOURCE_DIRECTORY(.          SRC_LIST)

# 7.生成目标(可执行文件)：cmaketest
ADD_EXECUTABLE(${PROJECT_NAME} ${SRC_LIST})

# 8.设置编译时依赖的subfunc静态库
target_link_libraries(${PROJECT_NAME}    #目标：cmaketest
    two_func
    subfunc        # sub子目录下的静态库文件
    subsubfunc     # subsub子目录下的静态库文件
)
