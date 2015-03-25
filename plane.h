/***************************************************************************
                          plane.h  -  description
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
// Plane.h: interface for the Plane class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PLANE_H__402A5020_1ED1_11D4_9A38_C0B647C10000__INCLUDED_)
#define AFX_PLANE_H__402A5020_1ED1_11D4_9A38_C0B647C10000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "threedimensionalshape.h"

class Plane : public ThreeDimensionalShape  
{
private:
	double a, b, c, d;	// coefficients of x, y, z and d in Ax + By + Cz + D = 0 
	Point3d* thru_point;	// point in the plane used when creating and finding normals

public:
	Plane(Point3d* thruPoint, Point3d* normal, double diff_ref, double spec_ref);

	virtual ~Plane();

	virtual bool intersects(Ray* r, Point3d* cam);
			//
			// Does the ray r intersect with this plane? pass t by refernce
			/////////////////////////////////////////////////////////////////////////
	
	virtual void calcNormal(Ray* norm, Point3d* inters);
			//
			// calculate normal unit vector at point where ray r intersects plane
			/////////////////////////////////////////////////////////////////////////
};

#endif // !defined(AFX_PLANE_H__402A5020_1ED1_11D4_9A38_C0B647C10000__INCLUDED_)
