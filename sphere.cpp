//////////////////////////////////////////////////////////////
//															//
//	Sphere.cpp	-	implementation of member functions		//
//															//
//////////////////////////////////////////////////////////////

#include "sphere.h"


///////////////////////////////////////////////////////////////////////////////////
//
// Constructor
//

Sphere::Sphere(double x, double y, double z, double rad, double diff_ref, double spec_ref)
{
    centre = new Point3d(x, y, z);
    radius = rad;
    diffuse = diff_ref;
    specular = spec_ref;
    red = blue = green = 0;
}


//////////////////////////////////////////////////////////////////////////
//
// Deconstructor
//

Sphere::~Sphere()
{
    delete centre;
}


//////////////////////////////////////////////////////////////////////////
//
// Intersects - does the ray r intersect this sphere?
//

bool Sphere::intersects(Ray* r, Point3d* cam)
{
    double a, b, c;	// coefficients in the sphere intersection quadratic equation
    // pow(x, 2) is x squared
    a = pow(r->delta_x, 2) + pow(r->delta_y, 2) + pow(r->delta_z, 2);

    b = 2 * (	(r->delta_x * (cam->x - centre->x))
                + (r->delta_y * (cam->y - centre->y))
                + (r->delta_z * (cam->z - centre->z)) );

    c =   pow((cam->x - centre->x), 2)
          + pow((cam->y - centre->y), 2)
          + pow((cam->z - centre->z), 2)
          - pow( radius, 2);

    // use formula for solving quadratic equations

    // roots = -b +/-  sqrt( b squared - 4ac)
    //		   ------------------------------
    //						2a

    // test b squared - 4ac  to see if it is negative - if is, can't be solved
    // hence this ray does not intersect sphere

    // use -b - etc. instead of -b +/- etc. as we only want to find
    // smallest root (closest intersection)

    if ( (pow( b, 2) - (4*a*c)) < 0 ) {
        //	cout << (pow( b, 2)) << endl;
        return false;
    } else {
        // if testing just for intersection just return true, we only need to test if
        // the sqrt part of eq. is non negative so we can get a sqrt value
        // but i'll find the smallest root (closest intersection) anyway

        r->t = ((0-b) - sqrt(pow(b, 2) - (4*a*c))) / (2*a);

        //	cout << "true" << endl;
        return true;
    }


}


//////////////////////////////////////////////////////////////////////////
//
// Calculate Unit Normal of point of intersection on sphere's surface
//

void Sphere::calcNormal(Ray* norm, Point3d* inters)
{

    double deltax, deltay, deltaz; // x,y,z of normal vector
    double vect_length;		// length of vector

    // normal is the unit vector from centre of sphere to point of intersection
    // unit vector between 2 points p0 and p1 is
    // (x1-x0, y1-y0, z1-z0)  -- same as a ray is calculated (deltax, deltay, deltaz)
    // where deltax = change in x
    // a UNIT vector has each co-ord divided by the length of the vector
    // the length is calculated as sqrt( sqr(deltax) + sqr(deltay) + sqr(deltaz) )
    // a bit like pythagorus theorem
    // so a UNIT vector is (deltax/vect_length, deltay/vect_length, deltaz/vect_length)

    /*	deltax = inters->x - centre->x;
    	deltay = inters->y - centre->y;
    	deltaz = inters->z - centre->z;

    	vect_length = sqrt( pow(deltax, 2) + pow(deltay, 2) + pow(deltaz, 2) );

    	// modify normal object that has its pointer passed in
    	// this is more efficient than creating and deleting new normals for every intersection
    	//	ie. use 1 normal object that is passed into this method and modify it

    	norm->delta_x = deltax / vect_length;
    	norm->delta_y = deltay / vect_length;
    	norm->delta_z = deltaz / vect_length;
    */
    norm->delta_x = (inters->x - centre->x) / radius;
    norm->delta_y = (inters->y - centre->y) / radius;
    norm->delta_z = (inters->z - centre->z) / radius;
}


//////////////////////////////////////////////////////////////////////////
//
// calculate x,y,z of intersection with ray r and store in inters
//

//void Sphere::calcIntersection(Ray* r, Point3d* cam, Point3d* inters)
//{
//	inters->x =

//}


//////////////////////////////////////////////////////////////////////////
//
// SetColour
//

//void Sphere::setColour(int r, int g, int b)
//{
//	red = r;
//	green = g;
//	blue = b;
//}
