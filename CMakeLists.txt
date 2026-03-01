# Minimum CMake version required
cmake_minimum_required(VERSION 3.13)

# Project name
project(lvgl-drm-app LANGUAGES C CXX)

# C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)

# C source files
file(GLOB APP_SOURCES "src/*.c")

# Set executable name
set(EXEC_NAME lvgl_gui)

# Force LVGL to not build demos, examples or ThorVG
set(CONFIG_LV_BUILD_DEMOS OFF CACHE BOOL "Disable demos" FORCE)
set(CONFIG_LV_BUILD_EXAMPLES OFF CACHE BOOL "Disable examples" FORCE)
set(CONFIG_LV_USE_THORVG_INTERNAL OFF CACHE BOOL "Disable internal ThorVG" FORCE)

# Set LV config path
set(LV_BUILD_CONF_PATH "${CMAKE_SOURCE_DIR}/inc/config/lv_conf.h" CACHE PATH "Custom lv_conf.h location")

# Add LVGL subdirectory
add_subdirectory(lvgl)

# C header files
target_include_directories(lvgl PRIVATE /usr/include/libdrm)
# Link DRM library
target_link_libraries(lvgl PRIVATE drm)

# Create the executable
add_executable(${EXEC_NAME} ${APP_SOURCES})

# C header files
target_include_directories(${EXEC_NAME}
    PRIVATE ${CMAKE_SOURCE_DIR}/inc
    PRIVATE /usr/include/libdrm
)

# Link LVGL library
target_link_libraries(${EXEC_NAME}
    PRIVATE lvgl
    PRIVATE drm
)

# Define LV_CONF_INCLUDE_SIMPLE so LVGL finds lv_conf.h
target_compile_definitions(${EXEC_NAME} PRIVATE LV_CONF_INCLUDE_SIMPLE)
