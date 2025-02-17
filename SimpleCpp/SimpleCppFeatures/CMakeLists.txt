# SimpleCpp/SimpleCppFeatures/CMakeLists.txt
add_library(SimpleCppFeatures INTERFACE
        SimpleReadWriteLock.h)

target_include_directories(SimpleCppFeatures INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
