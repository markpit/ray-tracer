/************************************************************************/
/************************************************************************/
/**																	   **/  
/**	tgademo.EXE -  application that produces output to				   **/
/**                 a TGA file.										   **/
/**																	   **/
/************************************************************************/
/************************************************************************/


#include "tgaimage.h"
#include <math.h>


int main()
{
	int i,j, down;
	int r,g,b;
	int x = 640;
	int y = 480;
	//unsigned long int count=0, pixtot = 0;
	TGAimage *picture;
	picture = new TGAimage("output.tga");
	picture->createNew(x,y);
	
//	pixtot = (unsigned long int)x*y;

//	float angle;
	for(j=0, b=0; j<y; j++)
	{
		r = 0;
		g = 0;
		b += 1;
		down=0;

	//	angle=(6.284*i)/x;	// calculate the angle for this screen pos.
	//	int value = 64*sin(3*angle);
		//picture.PutPixel(200, 200, 200, i, (y/2)+64*sin(angle));
	//	r = value % 255;
	//	b = value % 255;

		//if (count % 1000 == 0)    // mod
		//{
		//	percent = (int)(((float)count / (float)pixtot) * 100);
		//	int percent = ((float)j / (float)y) * 100;
		//	cout << percent << "% completed" << "\r";
		//}

		for(i=0; i<x; i++)
		{
			
			r++;
			g++;
			picture->setPixel(r, g, b, i, j);
		}
	}
		
//	picture->readImage();
	picture->getPixel(r, g, b, 300, 200);
	cout << endl << "Colour at 300 200  Red " << r << " Green " << g << " Blue " << b << " " << endl;
	picture->writeImage();
//	picture->blurImage();
	delete picture;
	return 0;
}