project(xcorelib VERSION 1.0.0)
add_library(xcorelib SHARED file.c)
target_compile_features(xcorelib PUBLIC c_std_11)
target_include_directories(xcorelib PUBLIC "${PROJECT_SOURCE_DIR}/../include/")
