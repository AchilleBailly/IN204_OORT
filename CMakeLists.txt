
#sets up the minimum version of cmake
cmake_minimum_required(VERSION 3.9) # personally I'd set this version as low as required; you don't have to require the cutting edge version

#how the project will be called
project (in204_oort)

#set the C++ standard to be used
set (CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#set source files
set (SOURCE_FILES src/main.cpp)



#we add the executable of the program
add_executable (in204_oort ${SOURCE_FILES})

find_package(SFML 2.5.1 COMPONENTS system graphics audio network REQUIRED)
target_link_libraries(in204_oort PRIVATE sfml-audio sfml-graphics sfml-network sfml-system)