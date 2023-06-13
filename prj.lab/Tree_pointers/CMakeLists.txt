add_library(Tree_p Tree_p.h Tree_p.cpp)

add_executable(Tree_p_test Tree_p_test.cpp)
target_link_libraries(Tree_p_test Tree_p)
