project(cat VERSION 1.0.0)
add_executable(cat cat.c)
target_compile_features(cat PUBLIC c_std_11)
target_link_libraries(cat PUBLIC xcorelib)
