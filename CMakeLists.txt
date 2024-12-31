cmake_minimum_required(VERSION 3.15)
project(arkanoid)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add the include directory for your project headers
include_directories(${CMAKE_SOURCE_DIR}/include)

# Find all source files
file(GLOB SOURCES "src/*.cpp" "src/controller/*.cpp" "src/model/*.cpp" "src/view/*.cpp")

# Add the executable
add_executable(arkanoid ${SOURCES})

# Link libraries for Allegro using pkg-config
find_package(PkgConfig REQUIRED)
pkg_check_modules(ALLEGRO REQUIRED allegro-5 allegro_primitives-5 allegro_font-5 allegro_ttf-5)

# Link Allegro libraries
target_link_libraries(arkanoid ${ALLEGRO_LIBRARIES})

# Add include directories for Allegro (make it PUBLIC for better IDE integration)
target_include_directories(arkanoid PUBLIC ${ALLEGRO_INCLUDE_DIRS})

# Optionally, link additional libraries if necessary (e.g., for Allegro-specific modules)
# target_link_libraries(arkanoid some_other_library)
