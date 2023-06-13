add_library(ptrList ptrList.h ptrList.cpp)

add_executable(ptrList_test ptrList_test.cpp)
target_link_libraries(ptrList_test ptrList)