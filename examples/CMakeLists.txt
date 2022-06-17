##############################################################################
# Project info
##############################################################################

cmake_minimum_required(VERSION 3.1.3)

project(example-universal_pddl_parser)

#find_package(universal_pddl_parser REQUIRED)

include_directories(${UNIVERSAL_PDDL_PARSER_INCLUDE_DIRS})
add_executable(parser parser/parser.cpp)
target_link_libraries(parser universal_pddl_parser)

