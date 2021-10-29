project(cat VERSION 1.0.0)
add_executable(cat cat.c)
target_include_directories(cat PUBLIC "${PROJECT_SOURCE_DIR}/../../lib/include/")
target_link_libraries(cat PUBLIC "${PROJECT_SOURCE_DIR}/file.lib")
