#     Copyright 2022 Institute of Industrial and Control Engineering (IOC)
#                  Universitat Politecnica de Catalunya
#                  BarcelonaTech
#     All Rights Reserved.
#
#     This program is free software; you can redistribute it and/or modify
#     it under the terms of the GNU General Public License as published by
#     the Free Software Foundation; either version 2 of the License, or
#     (at your option) any later version.
#
#     This program is distributed in the hope that it will be useful,
#     but WITHOUT ANY WARRANTY; without even the implied warranty of
#     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#     GNU General Public License for more details.
#
#     You should have received a copy of the GNU General Public License
#     along with this program; if not, write to the
#     Free Software Foundation, Inc.,
#     59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
#
#    Author:   Leopold Palomo-Avellaneda
#

##############################################################################
# Project info
##############################################################################

cmake_minimum_required(VERSION 3.1.3)

project(universal_pddl_parser VERSION 0.0.1 LANGUAGES CXX)


set(PROJECT_NAME universal_pddl_parser)
set(PROJECT_BUGREPORT leopold.palomo@upc.edu)
set(
  PROJECT_STRING
  "${PROJECT_NAME} ${PROJECT_VERSION}"
  "An algorithm for parsing any planning problem in PDDL format."
)
set(PROJECT_TARNAME ${PROJECT_NAME})
set(PROJECT_NAME_VERSION
  ${PROJECT_NAME_MAJOR_VERSION}.${PROJECT_NAME_MINOR_VERSION}.${PROJECT_NAME_PATCH_VERSION})

# some needed stuff
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

add_definitions(-Wall -Wextra -Wpedantic)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${PROJECT_SOURCE_DIR}/include/pddl_parser)
add_subdirectory(parser)


# Build basic example, test program
add_subdirectory (examples)

##############################################################################
# File describing how to use library
##############################################################################

#############
## Install ##
#############
install(
  DIRECTORY include/pddl_parser
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/
)

install(
  TARGETS ${PROJECT_NAME}
  EXPORT export_${PROJECT_NAME}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)


##############################################################################
# File describing how to use library
##############################################################################
# Export the package for use from the build-tree
# (this registers the build-tree with a global CMake-registry)

set(INCLUDE_INSTALL_DIR ${CMAKE_INSTALL_INCLUDEDIR})

# Create the ${PROJECT_NAME}Config.cmake.
configure_package_config_file(
  ${PROJECT_SOURCE_DIR}/parser/${PROJECT_NAME}Config.cmake.in
  "${PROJECT_BINARY_DIR}/${CMAKE_FILES_DIRECTORY}/${PROJECT_NAME}Config.cmake"
  PATH_VARS INCLUDE_INSTALL_DIR
  INSTALL_DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/${PROJECT_NAME}/cmake
)

# Create the ${PROJECT_NAME}ConfigVersion.cmake.
write_basic_package_version_file(
  ${PROJECT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
  COMPATIBILITY AnyNewerVersion
)

# cmake stuff files
install(
  FILES
    "${PROJECT_BINARY_DIR}/${CMAKE_FILES_DIRECTORY}/${PROJECT_NAME}Config.cmake"
    "${PROJECT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
  DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/${PROJECT_NAME}/cmake
)

# Export targets.
set(export_targets ${export_targets};${PROJECT_NAME})
export(
  EXPORT export_${PROJECT_NAME}
  FILE "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Targets.cmake"
  NAMESPACE ${PROJECT_NAME}::
)

install(
  EXPORT export_${PROJECT_NAME}
  DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/${PROJECT_NAME}/cmake
  FILE ${PROJECT_NAME}Targets.cmake
  NAMESPACE ${PROJECT_NAME}::
)

# package xml
install(
  FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/package.xml"
  DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/${PROJECT_NAME}/
)
