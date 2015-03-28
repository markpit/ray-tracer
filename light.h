#ifndef light_h
#define light_h


//******************************************//
//											//
//	Light.h - header file for light class	//
//											//
//******************************************//


#include "point3d.h"


class Light : public Point3d {		//	inherits Point3d
public:

    int r, g, b;  // could make these doubles?
    double intensity;

    Light(double xpos, double ypos, double zpos, int red, int green, int blue, double intens);
    //
    // Constructor
    ///////////////////////////////////////////////////////////////////////////


};

#endif
