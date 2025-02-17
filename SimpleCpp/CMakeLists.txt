# 指定源文件路径
project(SimpleCpp)

add_subdirectory(SimpleSTL)
add_subdirectory(SimpleCppFeatures)

add_executable(SimpleCpp main.cpp)  # 假设 SimpleCpp 有 main.cpp
target_include_directories(SimpleCpp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# 生成可执行文件用
target_link_libraries(SimpleCpp PUBLIC SimpleSTL SimpleCppFeatures)