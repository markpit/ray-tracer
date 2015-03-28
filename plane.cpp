/*************************************************
**
** Plane.cpp: implementation of the Plane class.
** created: Tue Sep 12 2000
**
*************************************************/

#include "plane.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Plane::Plane(Point3d* thruPoint, Point3d* normal, double diff_ref, double spec_ref)
{
    diffuse = diff_ref;
    specular = spec_ref;

    thru_point = new Point3d;
    thru_point->x = thruPoint->x;
    thru_point->y = thruPoint->y;
    thru_point->z = thruPoint->z;

    a = normal->x;
    b = normal->y;
    c = normal->z;
    d = (normal->x * (0-thruPoint->x)) +
        (normal->y * (0-thruPoint->y)) +
        (normal->z * (0-thruPoint->z));

    // normalize
    double length = sqrt( pow(a, 2) +
                          pow(b, 2) +
                          pow(c, 2) );
    a = a / length;
    b = b / length;
    c = c / length;
    d = d / length;


}

Plane::~Plane()
{
    delete thru_point;
}


bool Plane::intersects(Ray* r, Point3d* cam)
{
    double top_half = (a*cam->x) + (b*cam->y) + (c*cam->z) + d;
    double denominator = (a*r->delta_x) + (b*r->delta_y) + (c*r->delta_z);

    if ((denominator == 0) || (denominator > 0)) // do not intersect
        return false;
    else {
        r->t = 0 - ( top_half / denominator);
        return true;
    }
}

void Plane::calcNormal(Ray* norm, Point3d* inters)
{

    norm->delta_x = (inters->x - thru_point->x) + a;
    norm->delta_y = (inters->y - thru_point->y) + b;
    norm->delta_z = (inters->z - thru_point->z) + c;

}
