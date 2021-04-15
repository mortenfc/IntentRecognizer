cmake_minimum_required(VERSION 3.20)
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
# add_executable(${PROJECT_NAME}_test ${TESTS} ${PROJECT_src})
# target_link_libraries(${PROJECT_NAME}_test ${PROJECT_LIBS})
# gtest_add_tests(TARGET ${PROJECT_NAME}_test)

# set(BINARY ${CMAKE_PROJECT_NAME}_tst)
# set(TEST_SOURCES tests/are_words_similar_tests.cpp)
# set(SOURCES ${TEST_SOURCES})
# add_executable(${BINARY} ${TEST_SOURCES})
# add_test(NAME ${BINARY} COMMAND ${BINARY})
# target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME}_lib gtest)
set(GTest_ROOT /usr/src/googletest/googletest)
add_subdirectory(${GTest_ROOT}
        "${CMAKE_CURRENT_BINARY_DIR}/googletest" EXCLUDE_FROM_ALL)
add_executable(all_tests_binaries tests/are_words_similar_tests.cpp)
add_test(NAME all_tests_binaries COMMAND all_tests_binaries)
target_link_libraries(all_tests_binaries gtest_main)