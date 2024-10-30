#include <math.h>

typedef struct crds{
    int x;
    int y;
} coords;

//set up for global coords
/*
    given width x and heigth y, the center must be (0,0) and corners must be(x/2, y/2)
    (-x/2, y/2)             (x/2, y/2)


                   (0,0)      


    (-x/2, -y/2)            (x/2, -y/2) 
    normalize global to (-1 -> 1, -1 -> 1)
    to get "pixel" coords based on normalized coords, multiply by 1/2 of x and y respectively
*/
//setup for print coords
/*
    for x in terminal "coords", print space, print next line for y
    since technically, terminal "coords" are
    (0,0)               (x, 0)


             (x/2/y2)


    (0, y)              (x,y)
    we have to convert pixel coords to terminal "coords"
*/
