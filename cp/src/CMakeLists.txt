project(cp VERSION 1.0.0)
add_executable(cp cp.c)
target_compile_features(cp PUBLIC c_std_11)
target_link_libraries(cp PUBLIC xcorelib)