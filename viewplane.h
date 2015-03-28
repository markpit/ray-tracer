#ifndef viewplane_h
#define viewplane_h


//******************************************************************************//
//																				//
//	Viewplane.h - header file for viewplane object. The viewplane is			//
//		a "window" onto the 3D world which has a "blank" image stretched		//
//		across it. This uses TGAimage to record the image that is ray traced.	//
//																				//
//******************************************************************************//

#include "tgaimage.h"
#include "point3d.h"


class Viewplane {
private:

    TGAimage* image;				// image file used for output
    int image_x, image_y;			// size of image
    double pixel_x, pixel_y;				// size of pixel stretched onto viewplane
    const double view_x;			// x size of view plane
    const double view_y;			// y size of view plane
    Point3d* bot_left;				// bottom left of image - used for reference (z plane)


public:

    Viewplane(double xref, double yref, double zref, int img_x, int img_y);
    //
    // Constructor
    ///////////////////////////////////////////////////////////////////////////


    ~Viewplane();
    //
    // Deconstructor
    ///////////////////////////////////////////////////////////////////////////


    void setBottomLeft(double x, double y, double z);
    //
    // SetTopLeft - sets the top left of the viewplane  (z plane)
    ///////////////////////////////////////////////////////////////////////////


    double getxSize();
    //
    // GetxSize - returns x size of viewplane
    ///////////////////////////////////////////////////////////////////////////


    double getySize();
    //
    // GetySize - returns y size of viewplane
    ///////////////////////////////////////////////////////////////////////////


    double getPixelxSize();
    //
    // GetPixelSize - returns size of pixel on the viewplane
    ///////////////////////////////////////////////////////////////////////////


    double getPixelySize();
    //
    // GetPixelSize - returns size of pixel on the viewplane
    ///////////////////////////////////////////////////////////////////////////


    double getBottomLeftx();
    //
    // GetbottomLeftx - returns x pos of bottom left of viewplane (z= 0 plane)
    ///////////////////////////////////////////////////////////////////////////


    double getBottomLefty();
    //
    // GetbottomLefty - returns y pos of bot left of viewplane (z= 0 plane)
    ///////////////////////////////////////////////////////////////////////////


    double getBottomLeftz();
    //
    // GetbottomLeftz - returns z pos of bot left of viewplane (z= 0 plane)
    ///////////////////////////////////////////////////////////////////////////


    void setImageSize(int xsize, int ysize);
    //
    // setImageSize - changes the size of the output image
    ///////////////////////////////////////////////////////////////////////////


    int getImagexSize();
    //
    // getImagexSize - returns x size of image
    ///////////////////////////////////////////////////////////////////////////


    int getImageySize();
    //
    // getImageySize - returns y size of image
    ///////////////////////////////////////////////////////////////////////////

    void colourPixel(int red, int green, int blue, int x, int y);
    //
    // colourPixel - "colours in" the pixel x,y in the viewplane (image)
    ///////////////////////////////////////////////////////////////////////////




};


#endif

