project(seq VERSION 1.0.0)
add_executable(seq seq.c)
target_compile_features(seq PUBLIC c_std_11)
target_link_libraries(seq PUBLIC xcorelib)
