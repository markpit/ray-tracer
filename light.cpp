//**************************************************//
//													//
//	Light.cpp - member functions for light class	//
//													//
//**************************************************//


#include "light.h"



///////////////////////////////////////////////////////////////////////////////////
//
// Constructor
//

Light::Light(double xpos, double ypos, double zpos, int red, int green, int blue, double intens)
{
	x = xpos;
	y = ypos;
	z = zpos;
	r = red;
	g = green;
	b = blue;
	intensity = intens;
}
