cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(intent_recognizer)

include_directories(include)
include_directories(${Boost_INCLUDE_DIR})

set(PROJECT_SOURCE src/main.cpp)
set(PROJECT_LIBS ${Boost_LIBRARIES})
add_executable(${PROJECT_NAME} ${PROJECT_SOURCE})
target_link_libraries(${PROJECT_NAME} ${PROJECT_LIBS})
