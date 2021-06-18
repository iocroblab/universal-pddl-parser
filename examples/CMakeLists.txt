##############################################################################
# Project info
##############################################################################

cmake_minimum_required(VERSION 3.1.3)

project(example-universal-pddl-parser)

find_package(universal-pddl-parser REQUIRED)

message(STATUS "Universal ppd parser at: ${UNIVERSAL-PDDL-PARSER_LIBRARY} with includes ${UNIVERSAL-PDDL-PARSER_INCLUDE_DIRS}")

include_directories(${UNIVERSAL-PDDL-PARSER_INCLUDE_DIRS})
add_executable(parser parser/parser.cpp)
target_link_libraries(parser ${UNIVERSAL-PDDL-PARSER_LIBRARY_STATIC})
