#ifndef ray_h
#define ray_h


//******************************************//
//											//
//	Ray.h - header file for ray class		//
//											//
//******************************************//

#include <math.h>

class Ray {
public:
    double delta_x, delta_y, delta_z; //change in x,y,z
    double t; //distance to intersect with an object

    Ray();
    //
    // Default Constructor
    ///////////////////////////////////////////////////////////////////////////

    Ray(double xdiff, double ydiff, double zdiff);
    //
    // Constructor with 3 params,
    ///////////////////////////////////////////////////////////////////////////

    void normalize();
    //
    // Normalize the ray (vector) - converts it to a unit vector
    ///////////////////////////////////////////////////////////////////////////

};


#endif
