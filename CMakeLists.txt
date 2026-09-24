cmake_minimum_required(VERSION 3.21)

project(
  hwlib_periodic_clock
  VERSION 0.2.0
  LANGUAGES CXX)

add_library(hwlib_periodic_clock INTERFACE)
add_library(Hwlib::periodic_clock ALIAS hwlib_periodic_clock)

target_include_directories(hwlib_periodic_clock
                           INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_features(hwlib_periodic_clock INTERFACE cxx_std_20)

# Dependants read the version from this property rather than from a variable: a
# variable set here is invisible in a sibling directory, and a stale one left in
# the parent scope would be read instead — a version check that silently passes.
set_target_properties(hwlib_periodic_clock PROPERTIES HWLIB_VERSION
                                                      ${PROJECT_VERSION})
