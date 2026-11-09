cmake_minimum_required(VERSION 3.16)

project(GUI_MAKER C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Main application
add_executable(mygui
    main.c
    src/core/error.c
    src/graphics/framebuffer.c
    src/graphics/pixel.c
)

# Framebuffer test
add_executable(test_framebuffer
    tests/test_pixel.c
    src/core/error.c
    src/graphics/framebuffer.c
    src/graphics/pixel.c
)

# Pixel test
add_executable(test_pixel
    tests/test_framebuffer.c
    src/core/error.c
    src/graphics/framebuffer.c
    src/graphics/pixel.c
)

# Header directories
target_include_directories(mygui PRIVATE
    include
    src
)

target_include_directories(test_framebuffer PRIVATE
    include
    src
)

target_include_directories(test_pixel PRIVATE
    include
    src
)
