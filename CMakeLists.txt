cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(intent_recognizer)

include_directories(include ${Boost_INCLUDE_DIR})

set(PROJECT_SRC src/recognize_intent.cpp src/are_words_similar.cpp src/main.cpp)
set(PROJECT_LIBS ${Boost_LIBRARIES})

add_library(${PROJECT_NAME}_lib ${PROJECT_SRC})
target_link_libraries(${PROJECT_NAME}_lib ${PROJECT_LIBS})

add_executable(${PROJECT_NAME}_exe ${PROJECT_SRC})
target_link_libraries(${PROJECT_NAME}_exe ${PROJECT_LIBS})

install(
  DIRECTORY ${CMAKE_SOURCE_DIR}/include/
  DESTINATION include
  FILES_MATCHING
  PATTERN "*.h*")

install(
  TARGETS ${PROJECT_NAME}_exe
  LIBRARY DESTINATION ${CMAKE_SOURCE_DIR}
  RUNTIME DESTINATION ${CMAKE_SOURCE_DIR})

set(GTest_ROOT /usr/src/googletest/googletest)
add_subdirectory(${GTest_ROOT} "${CMAKE_CURRENT_BINARY_DIR}/googletest"
                 EXCLUDE_FROM_ALL)
file(GLOB TESTS_SRC "tests/*.cpp")
add_executable(all_tests_binary ${TESTS_SRC})
add_test(NAME all_tests_binary COMMAND all_tests_binary)
target_link_libraries(all_tests_binary gtest_main ${PROJECT_NAME}_lib)
