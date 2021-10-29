project(wc VERSION 1.0.0)
add_executable(wc wc.c)
target_compile_features(wc PUBLIC c_std_11)
target_link_libraries(wc PUBLIC xcorelib)
