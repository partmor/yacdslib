include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../src)

# If pkg-config is not installed on the system, then the
# CHECK_INSTALL_DIR variable must be set to the install
# location of Check. For example, on Windows, this may
# be: C:/Program Files/check
# set(CHECK_INSTALL_DIR "C:/Program Files/check")

find_package(Check REQUIRED)
include_directories(${CHECK_INCLUDE_DIRS})
link_directories(${CHECK_LIBRARY_DIRS})

set(TEST_SOURCES
        test_main.c
        test_linked_list.c
        test_vector.c)

add_executable(test_ds ${TEST_SOURCES})
target_link_libraries(test_ds yacdslib ${CHECK_LIBRARIES})
add_test(NAME test_ds COMMAND test_ds)