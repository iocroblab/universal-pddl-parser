##############################################################################
# Project info
##############################################################################

cmake_minimum_required(VERSION 3.1.3)

project(universal-pddl-parser)

set(PROJECT_NAME universal-pddl-parser)
set(PROJECT_BUGREPORT leopold.palomo@upc.edu)
set(PROJECT_VERSION_MAJOR 0)
set(PROJECT_VERSION_MINOR 1)
set(
  PROJECT_STRING
  "${PROJECT_NAME} ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}"
  "An algorithm for parsing any planning problem in PDDL format."
)
set(PROJECT_TARNAME ${PROJECT_NAME})
set(PROJECT_VERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR})

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

add_definitions(-Wall -Wextra -Wpedantic)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${PROJECT_SOURCE_DIR}/include/universal-pddl-parser)
add_subdirectory(parser)

##############################################################################
# File describing how to use library
##############################################################################

set(INCLUDE_INSTALL_DIR "${CMAKE_INSTALL_PREFIX}/include")
set(LIBRARY_INSTALL_DIR "${CMAKE_INSTALL_LIBDIR}")

configure_package_config_file(
  "${CMAKE_SOURCE_DIR}/parser/universal-pddl-parser.cmake.in"
  "${CMAKE_BINARY_DIR}/universal-pddl-parser.cmake"
  INSTALL_DESTINATION  ${CMAKE_INSTALL_LIBDIR}/cmake/universal-pddl-parser
  PATH_VARS INCLUDE_INSTALL_DIR LIBRARY_INSTALL_DIR)

write_basic_package_version_file(
  ${CMAKE_BINARY_DIR}/universal-pddl-parserConfigVersion.cmake
  VERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
  COMPATIBILITY SameMajorVersion )

install(FILES ${CMAKE_BINARY_DIR}/universal-pddl-parserConfig.cmake
              ${CMAKE_BINARY_DIR}/universal-pddl-parserConfigVersion.cmake
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/universal-pddl-parser )
