cmake_minimum_required(VERSION 3.5)
project(user_package)

# Default to C99
if (NOT CMAKE_C_STANDARD)
    set(CMAKE_C_STANDARD 99)
endif ()

# Default to C++14
if (NOT CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 14)
endif ()

if (CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_compile_options(-Wall -Wextra -Wpedantic)
endif ()

# find dependencies
find_package(ament_cmake REQUIRED COMPONENTS)
find_package(library_pkg REQUIRED)

include_directories(
        ${library_pkg_INCLUDE_DIRS}
        ${ament_cmake_INCLUDE_DIRS}
)


#include_directories(include)


# Define the executable
add_executable(main src/main.cpp)
# Link the SimpleLibrary
target_link_libraries(main library_pkg::SimpleLibrary)
# Set dependecies
ament_target_dependencies(main library_pkg)

# Install the executable, so 'ros2 run' fill find it.
install(TARGETS
        main
        DESTINATION lib/${PROJECT_NAME}
        )


# Wrap it up :)
ament_package()
