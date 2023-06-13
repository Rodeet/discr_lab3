add_library(Tree_v Tree_v.h Tree_v.cpp)

add_executable(Tree_v_test Tree_v_test.cpp)
target_link_libraries(Tree_v_test Tree_v)
