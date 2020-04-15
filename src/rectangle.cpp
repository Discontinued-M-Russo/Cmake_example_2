//
// Created by Russo, Michelangelo (GE Global Research) on 3/4/18.
//

#include "rectangle.h"


// Default constructor
rectangle::rectangle() {
    width = 1;
    height = 1;
}

// parameter constructor implementation
rectangle::rectangle(int x, int y) {
    width = x;
    height = y;
}

void rectangle::set_values(int x, int y) {
    width = x;
    height = y;
}

int rectangle::area() {
    return width*height;
}