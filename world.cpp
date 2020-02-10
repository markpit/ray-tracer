//**********************************************************//
//															//
//	World.cpp - member functions for world class			//
//															//
//**********************************************************//


#include "world.h"

///////////////////////////////////////////////////////////////////////////////////
//
// Constructor
//
World::World()
{

    camera = NULL;
    light = NULL;
    viewplane = NULL;

}

///////////////////////////////////////////////////////////////////////////////////
//
// Deconstructor
//
World::~World()
{
    //delete shapes from vector
    for (unsigned int i=0; i < vecShapes.size(); i++) {
        delete vecShapes.at(i);
    }
    //delete vecShapes;
    vecShapes.erase(vecShapes.begin(), vecShapes.end());

    if (camera != NULL)
        delete camera;
    if (viewplane != NULL)
        delete viewplane;
    if (light != NULL)
        delete light;


}

///////////////////////////////////////////////////////////////////////////////////
//
// addShape - adds the shaoe to the shape vector
//
void World::addShape(ThreeDimensionalShape* theShape)
{
    vecShapes.push_back(theShape);
}

///////////////////////////////////////////////////////////////////////////////////
//
// addCamera - adds camera - the viewpoint
//
void World::addCamera(Point3d* cam)
{
    camera = cam;
}

///////////////////////////////////////////////////////////////////////////////////
//
// addLight - adds camera - the viewpoint
//
void World::addLight(Light* l)
{
    light = l;
}

///////////////////////////////////////////////////////////////////////////////////
//
// addViewplane - adds viewplane - the window on the world
//
void World::addViewplane(Viewplane* vp)
{
    viewplane = vp;
}

///////////////////////////////////////////////////////////////////////////////////
//
// render - renders the scene viewed through the viewplane to image "output.tga"
//
void World::render()
{
    //check everything has been set up
    if (camera == NULL || light == NULL || viewplane == NULL) {
        cout << "something not initialised for render() to work" << endl;
        return;
    }

    int image_x = viewplane->getImagexSize();
    int image_y = viewplane->getImageySize();

    double pix_x_cent = viewplane->getBottomLeftx() + (viewplane->getPixelxSize() / 2);
    double pix_y_cent = (viewplane->getBottomLefty() + viewplane->getySize() ) - (viewplane->getPixelySize() / 2);

    Ray* r = new Ray(0, 0, viewplane->getBottomLeftz() - camera->z);	// initialize a ray object for re-use
//	Ray* r = new Ray(pix_x_cent - camera->x, pix_y_cent - camera->y, vp->getBottomLeftz() - camera->z);


    Ray* normal = new Ray();	// more efficient to use 1 object and modify it
    // rather than creating and deleting objects for each intersection
    Ray* lray = new Ray();		// ray in direction from intersection to light
    Ray* refl = new Ray();
    Point3d* intersect = new Point3d();	// used for intersection co-ords

    //vector<ThreeDimensionalShape*>::iterator shapeIterator;	// vector iterator

    //have the ray equation here? in comments

    for(int y = 0; y < image_y; y++) {
        for(int x = 0; x < image_x; x++) {	//for each pixel in image
            r->delta_x = (pix_x_cent - camera->x);
            r->delta_y = (pix_y_cent - camera->y);
            // delta_z doesn't change - viewplane = zplane

            /////////////
            // find nearest shape hit
            double t = 0;
            ThreeDimensionalShape* shape_hit = NULL;

            for (unsigned int i = 0; i < vecShapes.size(); i++) {
                //if (s1->intersects(r, camera))
                if (vecShapes.at(i)->intersects(r, camera)) {
                    if ((t == 0) || (r->t < t)) {
                        //t is distamce of intersect from start of ray (camera, i think)
                        t = r->t;	// set t to first intersection or to nearest so far
                        shape_hit = vecShapes.at(i);
                    }
                }
            }
            //
            ////////////////

            if (t != 0) {	// if a shape is hit with this ray ie. t!=0

                r->t = t;	// set r->t back to t just for readability

                // calculate point of intersection
                intersect->x = camera->x + (r->t * r->delta_x);	// x = x0 + t(x1 - x0)
                intersect->y = camera->y + (r->t * r->delta_y);	// etc.
                intersect->z = camera->z + (r->t * r->delta_z);

                // calculate unit light ray at point of intersection
                lray->delta_x = light->x - intersect->x;
                lray->delta_y = light->y - intersect->y;
                lray->delta_z = light->z - intersect->z;


                shape_hit->calcNormal(normal, intersect);	// results stored in normal


                bool in_shadow = false;
                // check to see if point of intersection is in shadow

                for (unsigned int i = 0; i < vecShapes.size(); i++) {

                    if (!in_shadow && (vecShapes.at(i) != shape_hit))
                        //change intersects to getIntersect?
                        if (vecShapes.at(i)->intersects(lray, intersect))
                            if (lray->t < 1 && lray->t > 0) {
                                in_shadow = true;
                                break;
                            }

                }

                if (!in_shadow) {

                    lray->normalize(); //normalize after doing shadow detection -this is so 0<t<1 when doing shadows

                    double dotprod = normal->delta_x * lray->delta_x;
                    dotprod += normal->delta_y * lray->delta_y;
                    dotprod += normal->delta_z * lray->delta_z;
                    double diffuse = light->intensity * shape_hit->diffuse * dotprod;

                    //	cout << intens * s1->red << endl;

                    if (diffuse < 0) // if negative, normal must point away from light, in shadow
                        diffuse = 0;

                    // calculate specular
                    // calculate reflection ray

                    refl->delta_x = (normal->delta_x * 2 * dotprod) - lray->delta_x;
                    refl->delta_y = (normal->delta_y * 2 * dotprod) - lray->delta_y;
                    refl->delta_z = (normal->delta_z * 2 * dotprod) - lray->delta_z;
                    // normalize refl ray?
                    refl->normalize();


                    dotprod = refl->delta_x * lray->delta_x;
                    dotprod += refl->delta_y * lray->delta_y;
                    dotprod += refl->delta_z * lray->delta_z;

                    // raise R.L to the power of k, surface specular coefficient
                    double specular = pow(dotprod, shape_hit->specular);
                    if (specular < 0)
                        specular = 0;
                    /*	if (specular > 0.5)	// experimental
                    		diffuse = 0;	// specular stuff
                    */
                    //int red = (diffuse * s1->red) + (specular * l->r);
                    int red, green, blue;

                    red = (diffuse * shape_hit->red) + (specular * light->r);
                    if ( red> 255)
                        red = 255;
                    green = (diffuse * shape_hit->green) + (specular * light->g);
                    if ( green > 255)
                        green = 255;
                    blue = (diffuse * shape_hit->blue) + (specular * light->b);
                    if ( blue > 255)
                        blue = 255;

                    //	cout << specular << endl;

                    viewplane->colourPixel(red, green, blue, x, y);

                } else	// in shadow
                    viewplane->colourPixel(0, 0, 0, x, y);
            } else
                viewplane->colourPixel(0, 0, 0, x, y);


            if (x == image_x-1)  // if last pixel in row
                pix_x_cent = viewplane->getBottomLeftx() + (viewplane->getPixelxSize() / 2);
            else
                pix_x_cent += viewplane->getPixelxSize();
        }

        pix_y_cent -= viewplane->getPixelySize();
        if (y % 100 == 0)
            cout << "rendered line " << y << endl;
    }


    delete r;
    delete normal;
    delete lray;
    delete refl;
    delete intersect;
}


