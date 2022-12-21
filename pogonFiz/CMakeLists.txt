# CMakeList.txt : CMake project for pogonFiz, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

set(SFML_STATIC_LIBRARIES TRUE)

set(SFML_DIR "C:/Users/Stip3k/source/repos/pogonFiz/SFML-2.5.1/lib/cmake/SFML")
#set(SFML_DIR "./SFML-2.5.1/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS graphics window REQUIRED)

# Add source to this project's executable.
add_executable (pogonFiz "pogonFiz.cpp" "pogonFiz.h" "source/svet.cpp" "header/svet.h")

target_link_libraries(pogonFiz sfml-graphics)
