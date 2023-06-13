add_library(arrList arrList.h arrList.cpp)

add_executable(arrList_test arrList_test.cpp)
target_link_libraries(arrList_test arrList)