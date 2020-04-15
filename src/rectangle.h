//
// Created by Russo, Michelangelo (GE Global Research) on 3/4/18.
//

#ifndef UNTITLED1_RECTANGLE_H
#define UNTITLED1_RECTANGLE_H


class rectangle {
    int width, height;
public:
    rectangle ();               // default constructor
    rectangle (int x, int y);   // parameter constructor
    void set_values (int,int);
    int area();
};


#endif //UNTITLED1_RECTANGLE_H
