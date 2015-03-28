/***************************************************************************
                          threedimensionalshape.h  -  description
                             -------------------
    begin                : Tue Sep 12 2000

 ***************************************************************************/


#ifndef threedimensionalshape_h
#define threedimensionalshape_h


/*********************************************************************************/
/**																				**/
/**	 ThreeDimensionalShape.h -	Header file for 3DShape abstract base class 	**/
/**																				**/
/*********************************************************************************/



#include "point3d.h"
#include "ray.h"

class ThreeDimensionalShape {
public:

    int red, green, blue;		// red, green, blue components of surface colour
    double diffuse, specular;	// reflection colour

    virtual bool intersects(Ray* r, Point3d* cam) = 0;

    virtual void calcNormal(Ray* norm, Point3d* inters) = 0;
};



#endif
