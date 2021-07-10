cmake_minimum_required(VERSION 3.2)

project("anititle")

include_directories(external/anitomy)
file (GLOB anitomy_sources external/anitomy/anitomy/*.cpp)

add_executable(anititle ${anitomy_sources} src/main.cc)
target_compile_features(anititle PUBLIC cxx_auto_type)
target_link_libraries(anititle -static)
