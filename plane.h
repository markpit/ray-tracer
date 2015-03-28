/***************************************************************************
                          plane.h  -  description
                             -------------------
    begin                : Tue Sep 12 2000

 ***************************************************************************/


// Plane.h: interface for the Plane class.
//
//////////////////////////////////////////////////////////////////////

#include "threedimensionalshape.h"

class Plane : public ThreeDimensionalShape {
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

