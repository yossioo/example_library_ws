cmake_minimum_required(VERSION 3.5)
project(library_pkg)

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
find_package(ament_cmake REQUIRED)


# Define the library
add_library(SimpleLibrary SHARED include/SimpleLibrary/simple_library.cpp)

# Install the library
install(TARGETS
        SimpleLibrary
        EXPORT export_SimpleLibrary
        DESTINATION include/${PROJECT_NAME}
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin
        )

# This is used for further includes in another package
# Install headers
install(DIRECTORY include/
        DESTINATION include/${PROJECT_NAME}
        FILES_MATCHING PATTERN "*.hpp"
        PATTERN ".svn" EXCLUDE)
# Afterwards use:
# -->   #include <library_pkg/SimpleLibrary/simple_library.hpp>

# Another option is to omit the package name
install(DIRECTORY include/
        DESTINATION include/
        FILES_MATCHING PATTERN "*.hpp"
        PATTERN ".svn" EXCLUDE)
# -->   #include <SimpleLibrary/simple_library.hpp>


# Export ament stuff
ament_export_include_directories(include)
ament_export_interfaces(export_SimpleLibrary)
#ament_export_libraries(SimpleLibrary) # Is this another way to use it?

# Wrap it up :)
ament_package()
