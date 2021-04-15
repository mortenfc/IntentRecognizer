cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(intent_recognizer)

include_directories(include ${Boost_INCLUDE_DIR})

set(PROJECT_EXE src/main.cpp)
set(PROJECT_LIB src/are_words_similar.cpp)
set(PROJECT_src src/main.cpp src/are_words_similar.cpp)
set(PROJECT_LIBS ${Boost_LIBRARIES})

add_library(${PROJECT_NAME}_lib ${PROJECT_src})
target_link_libraries(${PROJECT_NAME}_lib ${PROJECT_LIBS})

add_executable(${PROJECT_NAME}_exe ${PROJECT_src})
target_link_libraries(${PROJECT_NAME}_exe ${PROJECT_LIBS})

install(
  DIRECTORY ${CMAKE_SOURCE_DIR}/include/
  DESTINATION include
  FILES_MATCHING
  PATTERN "*.h*")

install(TARGETS ${PROJECT_NAME}_exe 
    # LIBRARY DESTINATION ${CMAKE_SOURCE_DIR} 
    RUNTIME DESTINATION ${CMAKE_SOURCE_DIR})

# include(GoogleTest)
# set(TESTS tests/are_words_similar_tests.cpp)
# add_executable(${PROJECT_NAME}_test ${TESTS})
# gtest_add_tests(TARGET ${PROJECT_NAME}_test)
