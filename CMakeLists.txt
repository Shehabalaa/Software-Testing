cmake_minimum_required(VERSION  2.8)
project(test_game_engine CXX)

set(CMAKE_CXX_FLAGS "-g  -fprofile-arcs -ftest-coverage -w")
set(CMAKE_CXX_OUTPUT_EXTENSION_RELACE 1)


set(HMMsrc "./")
add_library(
    HMM
    ${HMMsrc}/HMM.h
)

set(TESThelpersSrc "./tests/")
add_library(
    TestHelpers
    ${TESThelpersSrc}/test_helpers.hpp
)

enable_testing()
add_definitions(-DBOOST_TEST_DYN_LINK -DHANDMADE_MATH_IMPLEMENTATION -DHANDMADE_MATH_CPP_MODE) 
set (BOOST_ROOT $ENV{boost_test})
find_package (Boost REQUIRED COMPONENTS unit_test_framework)
set_target_properties(HMM PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(TestHelpers PROPERTIES LINKER_LANGUAGE CXX)

include_directories (${Boost_INCLUDE_DIRS} ${HMMsrc} ${TEST_HELPERS_DIR})


set(TESTS_SRCS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/tests)

file(GLOB TESTS_SRCS ${TESTS_SRCS_DIR}/*.cpp)
foreach(testSrc ${TESTS_SRCS})
    #Extract the filename without an extension (NAME_WE)
    get_filename_component(testName ${testSrc} NAME_WE)

    #Add compile target
    add_executable(${testName} ${testSrc})

    #link to Boost libraries AND your targets and dependencies
    target_link_libraries(${testName} ${TestHelpers} ${Boost_LIBRARIES} HMM)
    
    add_test(${testName} ${testName})
endforeach(testSrc)

# set(testName "main_test")
# set(testSrc "main_test.cpp")

# #Add compile target
# add_executable(${testName} ${TESTS_SRCS_DIR}/${testSrc})

# #link to Boost libraries AND your targets and dependencies
# target_link_libraries(${testName} ${TestHelpers} ${Boost_LIBRARIES} HMM)

# # retister test for cmake test runner
# add_test(hmm_${testName} ${testName})

