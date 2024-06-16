# 指定源文件路径
include_directories(${CMAKE_SOURCE_DIR}/LRUCache)

# 添加可执行文件
add_executable(
        LRUCache main.cpp LRUCache.h
)