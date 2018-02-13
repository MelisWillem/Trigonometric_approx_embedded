add_executable(simple_test.out simple_test.c)
target_link_libraries(simple_test.out TRIO_lib)
target_link_libraries(simple_test.out m) # link with math.h