#ifndef world_h
#define world_h


//******************************************************************************//
//																				//
//	World.h - header file for the "world" object. The world is the container	//
//		for the objects that are to be rendered in our 3D world. This also		//
//		contains the main rendering algorithm.									//
//																				//
//******************************************************************************//


#include "light.h"
#include "point3d.h"
#include "ray.h"
#include "sphere.h"
#include "plane.h"
#include "viewplane.h"
#include "threedimensionalshape.h"
#include <math.h>
#include <vector>

using namespace std;

class World {
private:
    vector<ThreeDimensionalShape*> vecShapes;	//vector used to store our 3D objects
    Point3d* camera;				//the position of the camera (or eye)
    Viewplane* viewplane;					//the viewplane (or canvas) which is the window on our world.
    Light* light;			//our light in the world (only one light - sort of sun)


public:

    World();
    //
    // Constructor
    ///////////////////////////////////////////////////////////////////////////


    ~World();
    //
    // Deconstructor
    ///////////////////////////////////////////////////////////////////////////


    void addShape(ThreeDimensionalShape* theShape);
    //
    // addShape - adds a ThreeDimensionalShape to the world
    ///////////////////////////////////////////////////////////////////////////


    void addCamera(Point3d* cam);
    //
    // addCamera - adds a camera - the viewpoint
    ///////////////////////////////////////////////////////////////////////////


    void addLight(Light* l);
    //
    // addLight - the single light source for the world
    ///////////////////////////////////////////////////////////////////////////


    void addViewplane(Viewplane* vp);
    //
    // addViewplane - the window on the world that we look through - has image stretched across it
    ///////////////////////////////////////////////////////////////////////////


    void render();
    //
    // render - renders the image
    ///////////////////////////////////////////////////////////////////////////




};


#endif
