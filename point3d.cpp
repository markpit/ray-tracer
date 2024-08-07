//////////////////////////////////
//								//
//	Point3d member functions	//
//	------------------------	//
//////////////////////////////////


#include "point3d.h"


///////////////////////////////////////////////////////////////////////////////////
//
// Constructor
//

Point3d::Point3d() {
    x = y = z = 0;
}



///////////////////////////////////////////////////////////////////////////////////
//
// Constructor with 3 params, sets point to xpos, ypos, zpos
//

Point3d::Point3d(double xpos, double ypos, double zpos) {
    x = xpos;
    y = ypos;
    z = zpos;
}


