cmake_minimum_required(VERSION 3.10)
project(MyProject)

set(CMAKE_CXX_STANDARD 11)

# Add the source files for your project
set(SOURCES
    main.cpp
    Dato.cpp
    LinkedList.cpp
)

# Add the header files for your project
set(HEADERS
    Dato.h
    LinkedList.h
)

add_executable(main ${SOURCES} ${HEADERS})
