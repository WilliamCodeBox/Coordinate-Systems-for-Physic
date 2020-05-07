add_executable(CosphyTests "${CMAKE_CURRENT_SOURCE_DIR}/test_main.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/source/test_cartesian.cpp")
target_include_directories(CosphyTests PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}" "${PROJECT_SOURCE_DIR}/include")
target_link_libraries(CosphyTests PRIVATE cosphy)
set_target_properties(CosphyTests PROPERTIES CXX_STANDARD 11)