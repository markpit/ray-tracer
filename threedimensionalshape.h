
/***************************************************************************
                          threedimensionalshape.h  -  description
                             -------------------
    begin                : Tue Sep 12 2000
    copyright            : (C) 2000 by Mark Pitten
    email                : 
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/
#ifndef threedimensionalshape_h
#define threedimensionalshape_h


/*********************************************************************************/
/**																				**/
/**	 ThreeDimensionalShape.h -	Header file for 3DShape abstract base class used in ray-tracer	**/
/**																				**/				
/*********************************************************************************/



#include "point3d.h"
#include "ray.h"

class ThreeDimensionalShape
{
public:

	int red, green, blue;		// red, green, blue components of surface colour
	double diffuse, specular;	// reflection colour
	
	virtual bool intersects(Ray* r, Point3d* cam) = 0;
	
	virtual void calcNormal(Ray* norm, Point3d* inters) = 0;
};



#endif