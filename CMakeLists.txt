# -----------------------------------------------------------------------------
#
# This file is part of the µOS++ project (https://micro-os-plus.github.io/).
# Copyright (c) 2025 Liviu Ionescu. All rights reserved.
#
# Permission to use, copy, modify, and/or distribute this software
# for any purpose is hereby granted, under the terms of the MIT license.
#
# If a copy of the license was not distributed with this file, it can
# be obtained from https://opensource.org/licenses/mit.
#
# -----------------------------------------------------------------------------

# This file is intended to be consumed by applications with:
#
# `add_subdirectory("xpacks/@xpack-segger/system-view
# The result is an interface library that can be added to the linker with:
#
# `target_link_libraries(your-target PUBLIC segger::system-view)`

# -----------------------------------------------------------------------------
# Preamble.

# https://cmake.org/cmake/help/v3.20/
cmake_minimum_required(VERSION 3.20)

project(segger-system-view
  DESCRIPTION "SEGGER SystemView"
)

if(COMMAND xpack_get_package_name_and_version)
  xpack_get_package_name_and_version("${CMAKE_CURRENT_SOURCE_DIR}/package.json")
  message(VERBOSE "Processing xPack ${PACKAGE_JSON_NAME}@${PACKAGE_JSON_VERSION}...")
endif()

# -----------------------------------------------------------------------------
# The project library definitions.
add_library(segger-system-view-interface INTERFACE EXCLUDE_FROM_ALL)

# -----------------------------------------------------------------------------
# Target settings.
target_include_directories(segger-system-view-interface INTERFACE
  "SYSVIEW"
  "SEGGER"
  "include"
)

target_sources(segger-system-view-interface INTERFACE
  "SYSVIEW/SEGGER_SYSVIEW.c"
  "src/instrumentation-sysview-micro-os-plus-iii.cpp"
)

target_compile_definitions(segger-system-view-interface INTERFACE

  # None.
)

target_compile_options(segger-system-view-interface INTERFACE

  # None.
)

target_link_options(segger-system-view-interface INTERFACE

  # None.
)

target_link_libraries(segger-system-view-interface INTERFACE

  # None.
)

if(COMMAND xpack_display_target_lists)
  xpack_display_target_lists(segger-system-view-interface)
endif()

# -----------------------------------------------------------------------------
# Aliases.

# https://cmake.org/cmake/help/v3.20/command/add_library.html#alias-libraries
add_library(segger::system-view ALIAS segger-system-view-interface)
message(VERBOSE "> segger::system-view -> segger-system-view-interface")

# -----------------------------------------------------------------------------
