cmake_minimum_required(VERSION 3.21)

project(
  integra_periodic_clock
  VERSION 0.1.0
  LANGUAGES CXX)

add_library(integra_periodic_clock INTERFACE)
add_library(Integra::periodic_clock ALIAS integra_periodic_clock)

target_include_directories(integra_periodic_clock
                           INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_features(integra_periodic_clock INTERFACE cxx_std_20)

# Dependants read the version from this property rather than from a variable: a
# variable set here is invisible in a sibling directory, and a stale one left in
# the parent scope would be read instead — a version check that silently passes.
set_target_properties(integra_periodic_clock PROPERTIES INTEGRA_VERSION
                                                        ${PROJECT_VERSION})
