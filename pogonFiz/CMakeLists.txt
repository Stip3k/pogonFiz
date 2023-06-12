# CMakeList.txt : CMake project for pogonFiz, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

set(SFML_STATIC_LIBRARIES TRUE)

set(SFML_DIR "${CMAKE_SOURCE_DIR}/SFML-2.5.1/lib/cmake/SFML")
message("Trenutna pot do projekta: ${CMAKE_SOURCE_DIR}/SFML-2.5.1/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS graphics window REQUIRED)

# Add source to this project's executable.
add_executable (pogonFiz "pogonFiz.cpp" "pogonFiz.h"
						 "include/src/svet.cpp" "include/header/svet.h"
						 "include/src/pogon.cpp" "include/header/pogon.h"
						 "include/header/telo.h" "include/src/telo.cpp"
						 "include/header/krog.h" "include/src/krog.cpp"
						 "include/header/krogList.h"    "include/header/upraviteljTeles.h" "include/src/upraviteljTeles.cpp" "include/src/pravokotnik.cpp" "include/header/pravokotnik.h" "include/header/pravokotnikList.h"  )

target_link_libraries(pogonFiz sfml-graphics)
