cmake_minimum_required(VERSION 3.9)
project(Rectangle)

set(CMAKE_CXX_STANDARD 14)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)

# REMEMBER to set BOOST_ROOT env variable to the root folder where Boost was installed
set(BOOST_LIBRARYDIR $(BOOST_ROOT)/lib)
set(BOOST_INCLUDEDIRS $(BOOST_ROOT)/include/boost)

find_package(Boost COMPONENTS unit_test_framework
         log_setup log filesystem thread system REQUIRED)

include_directories ($(BOOST_ROOT))
include_directories ($(BOOST_LIBRARYDIR))
include_directories ($(BOOST_INCLUDEDIRS))
include_directories (src)

add_subdirectory(test)

add_executable(rectangle main.cpp src/rectangle.cpp src/rectangle.h)

target_link_libraries(rectangle ${Boost_LIBRARIES})

