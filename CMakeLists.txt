cmake_minimum_required(VERSION 3.16)
project(thread)

set(ROOT ${PROJECT_SOURCE_DIR})

add_compile_options(-O3 -fPIC)


# include_directories(${ROOT}/src/cpp/thirdparty)
# include_directories(/opt/ros/noetic/include/)

# include_directories(
#     /usr/include
# )

# find_package(pybind11 REQUIRED)

# link_directories(${ROOT})
# link_directories(/opt/ros/noetic/lib/)


# add_library(basics SHARED ${ROOT}/src/to_py/basics.cpp)
# target_link_libraries(basics awm pybind11::module )

add_executable(thread ${ROOT}/01/thread.cpp)
target_link_libraries(thread pthread)

add_executable(detach ${ROOT}/01/detach.cpp)
target_link_libraries(detach pthread)

add_executable(create ${ROOT}/01/create.cpp)
target_link_libraries(create pthread)

# add_executable(test2 ${ROOT}/test2.cpp)