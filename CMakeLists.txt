cmake_minimum_required(VERSION 3.23)
project(BD2_Project)

# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Dependencies
set(RAYLIB_VERSION 4.5.0)
find_package(raylib ${RAYLIB_VERSION} QUIET) # QUIET or REQUIRED
if (NOT raylib_FOUND) # If there's none, fetch and build raylib
    include(FetchContent)
    FetchContent_Declare(
            raylib
            DOWNLOAD_EXTRACT_TIMESTAMP OFF
            URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
    )
    FetchContent_GetProperties(raylib)
    if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
        set(FETCHCONTENT_QUIET NO)
        FetchContent_Populate(raylib)
        set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
        add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
    endif()
endif()

# Our Project
add_executable(${PROJECT_NAME}
        src/main.cpp
        src/Scenes/Scenes.hpp
        src/Scenes/Headers/DAvl.hpp
        src/Scenes/Headers/DBTree.hpp
        src/Scenes/Headers/DExtendible.hpp
        src/Scenes/Headers/SceneCredits.hpp
        src/Scenes/Headers/SceneDocumen.hpp
        src/Scenes/Headers/SceneMainMenu.hpp
        src/Scenes/Headers/SceneStructuresDocumen.cpp
        src/Scenes/Headers/SceneStructuresVisualize.cpp
        src/Scenes/Headers/SceneVisualize.hpp
        src/Scenes/Headers/VAvl.hpp
        src/Scenes/Headers/VBTree.hpp
        src/Scenes/Headers/VExtendible.hpp

        src/GUI/Button.hpp

        src/proxy/apple_store_record.hpp
        src/proxy/proxy.hpp
        src/proxy/proxy.cpp

        src/structures/avl/avl.hpp
        src/structures/avl/node.hpp
        src/structures/avl/utils.hpp

        src/Util/GUIManager.hpp
        src/Util/SceneManager.hpp
        )
add_executable(test1 src/proxy/write_dat.cpp src/proxy/apple_store_record.hpp)
add_executable(test2 src/proxy/main.cpp
        src/proxy/proxy.hpp
        src/proxy/apple_store_record.hpp
        src/structures/avl/avl.hpp
        src/structures/avl/utils.hpp
        src/structures/avl/node.hpp
        )
#set(raylib_VERBOSE 1)
target_link_libraries(${PROJECT_NAME} raylib)

target_include_directories(${PROJECT_NAME} PRIVATE
        ${PROJECT_SOURCE_DIR}/src
        ${PROJECT_SOURCE_DIR}/src/
        ${PROJECT_SOURCE_DIR}/src/proxy
        ${PROJECT_SOURCE_DIR}/src/Scenes
        ${PROJECT_SOURCE_DIR}/src/structures
        ${PROJECT_SOURCE_DIR}/src/Util
)


# Web Configurations
if (${PLATFORM} STREQUAL "Web")
    set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".html")
endif()

# Checks if OSX and links appropriate frameworks (Only required on MacOS)
if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()
