# Install script for directory: D:/Documentos/Rodrigo/Utec/ciclo 2024-1/BD II/BD2_Project/cmake-build-debug/_deps/raylib_cpp-src/include

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/interfaz")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "C:/Users/leonc/AppData/Local/JetBrains/CLion 2022.2/bin/mingw/bin/objdump.exe")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES
    "D:/Documentos/Rodrigo/Utec/ciclo 2024-1/BD II/BD2_Project/cmake-build-debug/_deps/raylib_cpp-src/include/AudioDevice.hpp"
    "D:/Documentos/Rodrigo/Utec/ciclo 2024-1/BD II/BD2_Project/cmake-build-debug/_deps/raylib_cpp-src/include/AudioStream.hpp"
    "D:/Documentos/Rodrigo/Utec/ciclo 2024-1/BD II/BD2_Project/cmake-build-debug/_deps/raylib_cpp-src/include/BoundingBox.hpp"
    "D:/Documentos/Rodrigo/Utec/ciclo 2024-1/BD II/BD2_Project/cmake-build-debug/_deps/raylib_cpp-src/include/Camera2D.hpp"
    "D:/Documentos/Rodrigo/Utec/ciclo 2024-1/BD II/BD2_Project/cmake-build-debug/_deps/raylib_cpp-src/include/Camera3D.hpp"
    "D:/Documentos/Rodrigo/Utec/ciclo 2024-1/BD II/BD2_Project/cmake-build-debug/_deps/raylib_cpp-src/include/Color.hpp"
    "D:/Documentos/Rodrigo/Utec/ciclo 2024-1/BD II/BD2_Project/cmake-build-debug/_deps/raylib_cpp-src/include/Font.hpp"
    "D:/Documentos/Rodrigo/Utec/ciclo 2024-1/BD II/BD2_Project/cmake-build-debug/_deps/raylib_cpp-src/include/Functions.hpp"
    "D:/Documentos/Rodrigo/Utec/ciclo 2024-1/BD II/BD2_Project/cmake-build-debug/_deps/raylib_cpp-src/include/Gamepad.hpp"
    "D:/Documentos/Rodrigo/Utec/ciclo 2024-1/BD II/BD2_Project/cmake-build-debug/_deps/raylib_cpp-src/include/Image.hpp"
    "D:/Documentos/Rodrigo/Utec/ciclo 2024-1/BD II/BD2_Project/cmake-build-debug/_deps/raylib_cpp-src/include/Material.hpp"
    "D:/Documentos/Rodrigo/Utec/ciclo 2024-1/BD II/BD2_Project/cmake-build-debug/_deps/raylib_cpp-src/include/Matrix.hpp"
    "D:/Documentos/Rodrigo/Utec/ciclo 2024-1/BD II/BD2_Project/cmake-build-debug/_deps/raylib_cpp-src/include/Mesh.hpp"
    "D:/Documentos/Rodrigo/Utec/ciclo 2024-1/BD II/BD2_Project/cmake-build-debug/_deps/raylib_cpp-src/include/Model.hpp"
    "D:/Documentos/Rodrigo/Utec/ciclo 2024-1/BD II/BD2_Project/cmake-build-debug/_deps/raylib_cpp-src/include/ModelAnimation.hpp"
    "D:/Documentos/Rodrigo/Utec/ciclo 2024-1/BD II/BD2_Project/cmake-build-debug/_deps/raylib_cpp-src/include/Mouse.hpp"
    "D:/Documentos/Rodrigo/Utec/ciclo 2024-1/BD II/BD2_Project/cmake-build-debug/_deps/raylib_cpp-src/include/Music.hpp"
    "D:/Documentos/Rodrigo/Utec/ciclo 2024-1/BD II/BD2_Project/cmake-build-debug/_deps/raylib_cpp-src/include/Ray.hpp"
    "D:/Documentos/Rodrigo/Utec/ciclo 2024-1/BD II/BD2_Project/cmake-build-debug/_deps/raylib_cpp-src/include/RayCollision.hpp"
    "D:/Documentos/Rodrigo/Utec/ciclo 2024-1/BD II/BD2_Project/cmake-build-debug/_deps/raylib_cpp-src/include/RaylibException.hpp"
    "D:/Documentos/Rodrigo/Utec/ciclo 2024-1/BD II/BD2_Project/cmake-build-debug/_deps/raylib_cpp-src/include/raylib-cpp-utils.hpp"
    "D:/Documentos/Rodrigo/Utec/ciclo 2024-1/BD II/BD2_Project/cmake-build-debug/_deps/raylib_cpp-src/include/raylib-cpp.hpp"
    "D:/Documentos/Rodrigo/Utec/ciclo 2024-1/BD II/BD2_Project/cmake-build-debug/_deps/raylib_cpp-src/include/raylib.hpp"
    "D:/Documentos/Rodrigo/Utec/ciclo 2024-1/BD II/BD2_Project/cmake-build-debug/_deps/raylib_cpp-src/include/raymath.hpp"
    "D:/Documentos/Rodrigo/Utec/ciclo 2024-1/BD II/BD2_Project/cmake-build-debug/_deps/raylib_cpp-src/include/Rectangle.hpp"
    "D:/Documentos/Rodrigo/Utec/ciclo 2024-1/BD II/BD2_Project/cmake-build-debug/_deps/raylib_cpp-src/include/RenderTexture.hpp"
    "D:/Documentos/Rodrigo/Utec/ciclo 2024-1/BD II/BD2_Project/cmake-build-debug/_deps/raylib_cpp-src/include/Shader.hpp"
    "D:/Documentos/Rodrigo/Utec/ciclo 2024-1/BD II/BD2_Project/cmake-build-debug/_deps/raylib_cpp-src/include/Sound.hpp"
    "D:/Documentos/Rodrigo/Utec/ciclo 2024-1/BD II/BD2_Project/cmake-build-debug/_deps/raylib_cpp-src/include/Text.hpp"
    "D:/Documentos/Rodrigo/Utec/ciclo 2024-1/BD II/BD2_Project/cmake-build-debug/_deps/raylib_cpp-src/include/Texture.hpp"
    "D:/Documentos/Rodrigo/Utec/ciclo 2024-1/BD II/BD2_Project/cmake-build-debug/_deps/raylib_cpp-src/include/TextureUnmanaged.hpp"
    "D:/Documentos/Rodrigo/Utec/ciclo 2024-1/BD II/BD2_Project/cmake-build-debug/_deps/raylib_cpp-src/include/Touch.hpp"
    "D:/Documentos/Rodrigo/Utec/ciclo 2024-1/BD II/BD2_Project/cmake-build-debug/_deps/raylib_cpp-src/include/Vector2.hpp"
    "D:/Documentos/Rodrigo/Utec/ciclo 2024-1/BD II/BD2_Project/cmake-build-debug/_deps/raylib_cpp-src/include/Vector3.hpp"
    "D:/Documentos/Rodrigo/Utec/ciclo 2024-1/BD II/BD2_Project/cmake-build-debug/_deps/raylib_cpp-src/include/Vector4.hpp"
    "D:/Documentos/Rodrigo/Utec/ciclo 2024-1/BD II/BD2_Project/cmake-build-debug/_deps/raylib_cpp-src/include/VrStereoConfig.hpp"
    "D:/Documentos/Rodrigo/Utec/ciclo 2024-1/BD II/BD2_Project/cmake-build-debug/_deps/raylib_cpp-src/include/Wave.hpp"
    "D:/Documentos/Rodrigo/Utec/ciclo 2024-1/BD II/BD2_Project/cmake-build-debug/_deps/raylib_cpp-src/include/Window.hpp"
    )
endif()

