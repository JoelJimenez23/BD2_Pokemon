# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "D:/Documentos/Rodrigo/Utec/ciclo 2024-1/BD II/BD2_Project/cmake-build-debug/_deps/raylib_cpp-src"
  "D:/Documentos/Rodrigo/Utec/ciclo 2024-1/BD II/BD2_Project/cmake-build-debug/_deps/raylib_cpp-build"
  "D:/Documentos/Rodrigo/Utec/ciclo 2024-1/BD II/BD2_Project/cmake-build-debug/_deps/raylib_cpp-subbuild/raylib_cpp-populate-prefix"
  "D:/Documentos/Rodrigo/Utec/ciclo 2024-1/BD II/BD2_Project/cmake-build-debug/_deps/raylib_cpp-subbuild/raylib_cpp-populate-prefix/tmp"
  "D:/Documentos/Rodrigo/Utec/ciclo 2024-1/BD II/BD2_Project/cmake-build-debug/_deps/raylib_cpp-subbuild/raylib_cpp-populate-prefix/src/raylib_cpp-populate-stamp"
  "D:/Documentos/Rodrigo/Utec/ciclo 2024-1/BD II/BD2_Project/cmake-build-debug/_deps/raylib_cpp-subbuild/raylib_cpp-populate-prefix/src"
  "D:/Documentos/Rodrigo/Utec/ciclo 2024-1/BD II/BD2_Project/cmake-build-debug/_deps/raylib_cpp-subbuild/raylib_cpp-populate-prefix/src/raylib_cpp-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "D:/Documentos/Rodrigo/Utec/ciclo 2024-1/BD II/BD2_Project/cmake-build-debug/_deps/raylib_cpp-subbuild/raylib_cpp-populate-prefix/src/raylib_cpp-populate-stamp/${subDir}")
endforeach()
