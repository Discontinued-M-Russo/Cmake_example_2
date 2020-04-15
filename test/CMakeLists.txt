
add_executable (rectangleTest testRectangle.cpp ../src/rectangle.cpp ../src/rectangle.h)

target_link_libraries(rectangleTest ${Boost_LIBRARIES})
