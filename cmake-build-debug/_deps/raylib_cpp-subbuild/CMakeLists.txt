# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.23.2)

# We name the project and the target for the ExternalProject_Add() call
# to something that will highlight to the user what we are working on if
# something goes wrong and an error message is produced.

project(raylib_cpp-populate NONE)


# Pass through things we've already detected in the main project to avoid
# paying the cost of redetecting them again in ExternalProject_Add()
set(GIT_EXECUTABLE [==[D:/Downloads/Git/cmd/git.exe]==])
set(GIT_VERSION_STRING [==[2.36.0.windows.1]==])
set_property(GLOBAL PROPERTY _CMAKE_FindGit_GIT_EXECUTABLE_VERSION
  [==[D:/Downloads/Git/cmd/git.exe;2.36.0.windows.1]==]
)


include(ExternalProject)
ExternalProject_Add(raylib_cpp-populate
                     "UPDATE_DISCONNECTED" "False" "GIT_REPOSITORY" "https://github.com/Enriquefft/raylib-cpp.git"
                    SOURCE_DIR          "D:/Documentos/Rodrigo/Utec/ciclo 2024-1/BD II/BD2_Project/cmake-build-debug/_deps/raylib_cpp-src"
                    BINARY_DIR          "D:/Documentos/Rodrigo/Utec/ciclo 2024-1/BD II/BD2_Project/cmake-build-debug/_deps/raylib_cpp-build"
                    CONFIGURE_COMMAND   ""
                    BUILD_COMMAND       ""
                    INSTALL_COMMAND     ""
                    TEST_COMMAND        ""
                    USES_TERMINAL_DOWNLOAD  YES
                    USES_TERMINAL_UPDATE    YES
                    USES_TERMINAL_PATCH     YES
)


