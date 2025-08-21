# Radar Demo (Windows, C++17, Dear ImGui DX11)

Educational radar/ESP-style widget rendering 2D points from a JSON file. No game memory reading or bypasses. Buildable on Windows with CMake + Visual Studio using Dear ImGui (Win32 + DirectX 11).

## Prerequisites
- Visual Studio 2022 (Desktop development with C++)
- CMake 3.20+
- Git

## Build steps
1. Open "x64 Native Tools Command Prompt for VS 2022".
2. From the project root run:

```bat
cmake -S . -B build -G "Visual Studio 17 2022" -A x64
cmake --build build --config Release
```

3. Run the executable:

```bat
build\Release\RadarDemo.exe
```

The app loads entities from `data\sample_entities.json` and shows them on a radar.

## Layout
- `src\main.cpp`: Win32 + DirectX 11 bootstrap and ImGui loop
- `src\Radar.*`: math to project world positions into radar space
- `src\DataProvider.*`: loads entities from JSON (nlohmann/json)
- `external/`: CMake FetchContent for ImGui and nlohmann/json
- `data\sample_entities.json`: example dataset

## Notes
- For learning UI/math only. Use with your own apps or open-source demos.
- If you get a blank window, ensure your GPU supports Direct3D 11.
