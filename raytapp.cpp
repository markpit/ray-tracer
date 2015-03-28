/************************************************************************/
/************************************************************************/
/**																	   **/
/**	Raytapp - Raytracing application that produces output to	   **/
/**                 a TGA file.										   **/
/**																	   **/
/************************************************************************/
/************************************************************************/


#include "world.h"


const int image_x = 1024;
const int image_y = 768;

//x is to the right of image
//y is to the top of image
//z is into the image

/*
						^  y
						|		  z
						|	    /
						|	  /
						|   /
						| /
						/---------------> x


  */


/*
TODO:
02/11/01
  tidy up calcNormal and intersects method so that they don't modify the variables passed in
get them to return new point,vector etc.

  have a method in world to calculate if pixel is in shadow


  */

int main()
{
    cout << "starting ...." << endl;

    World* myWorld = new World();
    //set up camera
    Point3d* camera = new Point3d(5, 4, -10);
    myWorld->addCamera(camera);
    //set up light
    Light* l = new Light(8, 10, -3, 255, 255, 255, 1);
    myWorld->addLight(l);
    //set up viewplane
    Viewplane* vp = new Viewplane(0, 0, 0, image_x, image_y);
    myWorld->addViewplane(vp);

    /*	//blue
    	Sphere* s = new Sphere(3.7, 3, 3, 2, 1, 85);	// a sphere object
    	s->red = 5;
    	s->blue = 255;
    	s->green = 149;
    	myWorld->addShape(s);

    	//yellow
    	s = new Sphere(4.7, 5, 4, 1, 1, 85);	// a sphere object
    	s->red = 251;
    	s->blue = 67;
    	s->green = 227;
    	myWorld->addShape(s);

    	//red
    	s = new Sphere(6.2, 4.5, 1, 1, 1, 85);	// a sphere object
    	s->red = 178;
    	s->blue = 4;
    	s->green = 57;
    	myWorld->addShape(s);

    	//green
    	s = new Sphere(7, 3, 4, 1, 1, 85);	// a sphere object
    	s->red = 180;
    	s->blue = 180;
    	s->green = 250;
    	myWorld->addShape(s);

    */
    /*	Plane* p = new Plane(new Point3d(2,0,2), new Point3d(0,1,0), 4, 5);
    	p->red = 200;
    	p->green = 0;
    	p->blue = 50;
    	myWorld->addShape(p);
    */

    for (int z=0; z<15; z++) {
        for (int x=0; x<10; x++) {

            Sphere* s = new Sphere(x*2, 1, z*2, 1, 1, 85);	// a sphere object
            s->red = 255;
            s->blue = 0;
            s->green = 40;
            myWorld->addShape(s);
        }
    }

    myWorld->render();

    delete myWorld;

    return 0;


}
