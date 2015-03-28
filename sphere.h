#ifndef sphere_h
#define sphere_h


/*********************************************************************************/
/**																				**/
/**	 Sphere.h -	Header file for Sphere class, sphere object used in ray-tracer	**/
/**																				**/
/*********************************************************************************/

#include "threedimensionalshape.h"

class Sphere : public ThreeDimensionalShape {
private:

    Point3d* centre;			// centre of sphere x, y, z coordinates
    double radius;				// radius of sphere
    //	int red, green, blue;		// red, green, blue components of surface colour
    //	double diffuse, specular;	// reflection colour



public:

    //int red, green, blue;		// red, green, blue components of surface colour
    //double diffuse, specular;	// reflection colour


    Sphere(double x, double y, double z, double radius, double diff_ref, double spec_ref);
    //
    // Constructor
    //		x, y, z - the coordinates of the centre of the sphere
    //		radius - the radius of the sphere
    //		diff_ref, spec_ref - diffuse and specular reflection co-efficients
    ///////////////////////////////////////////////////////////////////////////

    ~Sphere();
    //
    // Deconstructor
    /////////////////////////////////////////////////////////////////////////

    virtual bool intersects(Ray* r, Point3d* cam);
    //
    // Does the ray r intersect with this sphere? pass t by refernce
    /////////////////////////////////////////////////////////////////////////

    virtual void calcNormal(Ray* norm, Point3d* inters);
    //
    // calculate normal unit vector at point where ray r intersects sphere
    /////////////////////////////////////////////////////////////////////////

    //	void calcIntersection(Ray* r, Point3d* cam, Point3d* inters);
    //
    // calculate x,y,z of intersection with ray r and store in inters
    /////////////////////////////////////////////////////////////////////////


    //	void setColour(int r, int g, int b);
    //
    // sets surface colour of sphere
    /////////////////////////////////////////////////////////////////////////
};



#endif
