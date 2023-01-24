# SPDX-FileCopyrightText: 2023 metaquarx <metaquarx@protonmail.com>
# SPDX-License-Identifier: Apache-2.0

# Setup

cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
project(Cornered VERSION 1.0.0 LANGUAGES CXX)

# Library

add_library(Cornered
	"src/RoundRect.cpp"
	"src/Squircle.cpp"
)

target_compile_features(Cornered PUBLIC cxx_std_17)
set_target_properties(Cornered PROPERTIES CXX_EXTENSIONS OFF)

target_include_directories(Cornered PUBLIC "${Cornered_SOURCE_DIR}/include/")

# Dependencies

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)
target_link_libraries(Cornered PUBLIC sfml-graphics)

# Examples

if (CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
	add_subdirectory(examples)
endif()
