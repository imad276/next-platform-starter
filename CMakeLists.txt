cmake_minimum_required(VERSION 3.20)
project(RadarDemoWinDX11 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(external)

add_executable(RadarDemo
    src/main.cpp
    src/Radar.h
    src/Radar.cpp
    src/DataProvider.h
    src/DataProvider.cpp
)

target_include_directories(RadarDemo PRIVATE external/imgui external/imgui/backends)

target_link_libraries(RadarDemo PRIVATE imgui_dx11_win32 nlohmann_json::nlohmann_json)

if (MSVC)
    target_compile_options(RadarDemo PRIVATE /W4 /permissive-)
else()
    target_compile_options(RadarDemo PRIVATE -Wall -Wextra -Wpedantic)
endif()

file(COPY data DESTINATION ${CMAKE_BINARY_DIR})
