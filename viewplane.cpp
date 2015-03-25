//**********************************************************//
//															//
//	Viewplane.cpp - member functions for viewplane class	//
//															//
//**********************************************************//


#include "viewplane.h"


///////////////////////////////////////////////////////////////////////////////////
//
// Constructor
//

Viewplane::Viewplane(double xref, double yref, double zref, int img_x, int img_y)
:view_x(10.24), view_y(7.68)
{
	bot_left = new Point3d(xref, yref, zref);
	image_x = img_x;
	image_y = img_y;
	pixel_x = view_x / image_x;
	pixel_y = view_y / image_y;

	image = new TGAimage("output.tga");
	image->createNew(image_x, image_y);

}


///////////////////////////////////////////////////////////////////////////////////
//
// Deconstructor
//

Viewplane::~Viewplane()
{
	delete bot_left;
	image->writeImage();	// save results to file
	delete image;
}


///////////////////////////////////////////////////////////////////////////////////
//
// getPixelxSize - returns pixel x size
//

double Viewplane::getPixelxSize()
{
	return pixel_x;
}


///////////////////////////////////////////////////////////////////////////////////
//
// getPixelySize - returns pixel y size
//
		
double Viewplane::getPixelySize()
{
	return pixel_y;
}


///////////////////////////////////////////////////////////////////////////////////
//
// getxSize - returns viewplane x size
//

double Viewplane::getxSize()
{
	return view_x;
}


///////////////////////////////////////////////////////////////////////////////////
//
// getySize - returns viewplane y size
//

double Viewplane::getySize()
{
	return view_y;
}


///////////////////////////////////////////////////////////////////////////////////
//
// getImagexSize - returns image x size
//

int Viewplane::getImagexSize()
{
	return image_x;
}


///////////////////////////////////////////////////////////////////////////////////
//
// getImageySize - returns image y size
//

int Viewplane::getImageySize()
{
	return image_y;
}


///////////////////////////////////////////////////////////////////////////////////
//
// getbottomLeftx - returns x co-ord of bottom left of viewplane
//

double Viewplane::getBottomLeftx()
{
	return bot_left->x;
}


///////////////////////////////////////////////////////////////////////////////////
//
// getbottomLefty - returns y co-ord of bottom left of viewplane
//

double Viewplane::getBottomLefty()
{
	return bot_left->y;
}


///////////////////////////////////////////////////////////////////////////////////
//
// getbottomLeftz - returns z co-ord of bottom left of viewplane
//

double Viewplane::getBottomLeftz()
{
	return bot_left->z;
}


///////////////////////////////////////////////////////////////////////////////////
//
// setImageSize - sets the size of the image in pixels
//

void Viewplane::setImageSize(int xsize, int ysize)
{
	delete image;		// delete current image object
	image_x = xsize;
	image_y = ysize;
	image = new TGAimage("output.tga");
	image->createNew(image_x, image_y);
}


///////////////////////////////////////////////////////////////////////////////////
//
// setBottomLeft - sets co-ords of bottom left of viewplane
//

void Viewplane::setBottomLeft(double x, double y, double z)
{
		delete bot_left;
		bot_left = new Point3d(x, y, z);
}


///////////////////////////////////////////////////////////////////////////////////
//
// colourPixel - sets the colour of pixel x,y on the viewplane
//

void Viewplane::colourPixel(int red, int green, int blue, int x, int y)
{
	// to do - check image exists first
	image->setPixel(red, green, blue, x, y);
}


