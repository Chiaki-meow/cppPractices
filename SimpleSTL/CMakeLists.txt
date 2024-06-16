# 指定源文件路径
include_directories(${CMAKE_SOURCE_DIR}/SimpleSTL)

# 添加可执行文件
add_executable(
        SimpleSTL main.cpp SimpleVector.h
)