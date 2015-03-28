//**************************************************//
//													//
//	Ray.cpp - Member function(s) for ray class		//
//													//
//**************************************************//


#include "ray.h"



///////////////////////////////////////////////////////////////////////////////////
//
// Constructor
//

Ray::Ray()
{
    delta_x = delta_y = delta_z = t = 0;
}


///////////////////////////////////////////////////////////////////////////////////
//
// Constructor 3 params
//

Ray::Ray(double xdiff, double ydiff, double zdiff)
{
    delta_x = xdiff;
    delta_y = ydiff;
    delta_z = zdiff;
    t = 0;
}


///////////////////////////////////////////////////////////////////////////////////
//
// Normalize this ray (vector of unit length)
//

void Ray::normalize()
{
    // find length of vector
    double vect_length = sqrt( pow(delta_x, 2) +
                               pow(delta_y, 2) +
                               pow(delta_z, 2) );
    // divide each component by the length of this vector - normalizing
    delta_x = delta_x / vect_length;
    delta_y = delta_y / vect_length;
    delta_z = delta_z / vect_length;

}
