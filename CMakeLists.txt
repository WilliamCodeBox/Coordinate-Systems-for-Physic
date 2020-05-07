# project
cmake_minimum_required(VERSION 3.16)
project               (cosphy VERSION 1.0.0 LANGUAGES CXX)

# options
set(BUILD_TESTS "Build the tests." ON)

# target
add_library               (cosphy SHARED "${CMAKE_CURRENT_SOURCE_DIR}/source/cartesian.cpp")
target_include_directories(cosphy PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
set_target_properties     (cosphy PROPERTIES CXX_STANDARD 11)

# test
if(BUILD_TESTS)
    add_subdirectory(test)
endif()


# install
