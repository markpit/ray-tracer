/************************************************************************/
/************************************************************************/
/*	Member functions for TGAimage class									*/
/************************************************************************/
/************************************************************************/




#include "tgaimage.h"


///////////////////////////////////////////////////////////////////////////////////
//
// Constructor
//

TGAimage::TGAimage(char* name)   
{
	image_data_offset = 18;	// pixel data starts at 18
	xsize = ysize = 0; // need to initialize them, they are 4 byte ints,
					   // reading 2 byte ints from file using SetRead


	int length = strlen(name);       // length of string argument
	filename = new char[length+1];   // get memory
	strcpy(filename,name);          // copy argument to it
	//***************************************************************//
	
}


//////////////////////////////////////////////////////////////////////////
//
// Deconstructor
//

TGAimage::~TGAimage(void)	// deconstructor
{
	delete[] filename;     // release memory for "filename" string
	free(pix_buff);
}


/////////////////////////////////////////////////////////////////////////
//
// Create New : 'Initialises' the current image associated with this 
//				  object ready for writing to. Effectively creating a new 
//				  image.
//

void TGAimage::createNew(int x, int y)	// have filename as parameter , not in constructor
{

	

	outfile.open(filename, ios::binary);	// open output file in binary mode
	
	xsize = x;				// copy image x size
	ysize = y;				// copy image y size
	
	pix_buff = (char*)calloc((xsize*ysize*3), sizeof(char));	// initialize pixel buffer

/*	cout 	<< endl << "Creating file " << filename
			<< " (" << xsize << " x " << ysize << ")" << endl;   // display filename
	
	//unsigned char data;
	outfile.seekp(0);                           //offset 0
	//unsigned short int value = 0;
	value = 0;
	outfile.write(reinterpret_cast<const char *>(&value), sizeof(char));		//put 0  - number of chars in ID field
	outfile.seekp(1);          //offset 1
	outfile.write(reinterpret_cast<const char *>(&value), sizeof(char));		//put 0 - no color map included
	outfile.seekp(2);			 	//offset 2
	value = 2;
	outfile.write(reinterpret_cast<const char *>(&value), sizeof(char));		//put 2 - image type code
	//image specification
		outfile.seekp(8);						//offset 8
		value = 0;
		outfile.write(reinterpret_cast<const char *>(&value), sizeof(short)); // 2 bytes	//put 0 - bottom left x co-ord
		outfile.seekp(10);					//offset 10
		outfile.write(reinterpret_cast<const char *>(&value), sizeof(short));// 2 bytes		//put 0 - bottom left y co-ord
		outfile.seekp(12);
		outfile.write(reinterpret_cast<const char *>(&xsize), sizeof(short));// 2 bytes   put xsize - width of image in pixels
		outfile.seekp(14);
		outfile.write(reinterpret_cast<const char *>(&ysize), sizeof(short));// 2 bytes   put ysize - height of image in pixels
		outfile.seekp(16);
		value = 24;
		outfile.write(reinterpret_cast<const char *>(&value), sizeof(char));	   //put 24 - 24 bits per pixel
		outfile.seekp(17);
		value = 32;
		outfile.write(reinterpret_cast<const char *>(&value), sizeof(char));	//image descriptor byte
												//put 00100000 = 32 or 00000100 = 4			
*/
}


/////////////////////////////////////////////////////////////////////////
//
//	Open Existing Image
//

void TGAimage::readImage()	// have filename as parameter , not in constructor
{
	infile.open(filename, ios::binary); // open input file in binary mode

	if (!(infile.is_open()))	// if file is not open for read then return
		return;			
	
	cout << "OPEN " << filename;
	
	/************ get x size and y size from file *********************/
	infile.seekg(12);
	infile.read(reinterpret_cast<char *>(&xsize), sizeof(short));	// 2 bytes
	infile.seekg(14);
	infile.read(reinterpret_cast<char *>(&ysize), sizeof(short));	// 2 bytes
	
	// check to make sure pix_buff isn't already pointing to an array, when reading in a second image - get memory leaks
	pix_buff = (char*)calloc((xsize*ysize*3), sizeof(char));

	infile.seekg(image_data_offset);
	infile.read(pix_buff, xsize*ysize*3*sizeof(char));	// sizeof(char) = 1 
	
	cout << "readImage() xsize " << xsize << ", ysize " << ysize;
	
}


/////////////////////////////////////////////////////////////////////////
//
//	Set Colour Of Pixel x,y
//

void TGAimage::setPixel(char red, char green, char blue, int x, int y)
{
	/*unsigned long filepos;  		// position of pointer in file

	filepos = (((y * (unsigned long)xsize) + x) * 3) + image_data_offset;
	
	outfile.seekp(filepos++); 	//start of this pixel's data
	outfile.write(reinterpret_cast<const char *>(&blue), sizeof(char));		// write pixel's blue data
	outfile.seekp(filepos++);
	outfile.write(reinterpret_cast<const char *>(&green), sizeof(char));		// write pixel's green data
	outfile.seekp(filepos);
	outfile.write(reinterpret_cast<const char *>(&red), sizeof(char));	// write pixel's red data
	*/

	// pixels stored | b, g, r | b, g, r | b, g, r | etc.
	// check if pix_buff exists
	//if (pix_buff != null)
	long pos = ((y * xsize) + x) * 3;
	
	pix_buff[pos] = blue;
	pix_buff[pos+1] = green;
	pix_buff[pos+2] = red;
}


//////////////////////////////////////////////////////////////////////////
//
// Get Pixel Colour
//

void TGAimage::getPixel(int& red, int& green, int& blue, int x, int y) 
{			// - pass r,g,b by reference and read values from file, put them in r,g,b

/*	unsigned long filepos;  		// position of pointer in file
	unsigned char r, g, b;
	r = g = b = 0;
	
	filepos = (((y * (unsigned long)xsize) + x) * 3) + image_data_offset;

	infile.seekg(filepos++); 	//start of this pixel's data
	infile.read(&b, sizeof(char));		// read pixel's blue data
	infile.seekg(filepos++);
	infile.read(&g, sizeof(char));		// read pixel's green data
	infile.seekg(filepos);
	infile.read(&r, sizeof(char));	// read pixel's red data
	
	  // return values in parameters passed by reference
	red = r;
	green = g;
	blue = b;
	// return true if no errors? try{} catch{}
	*/

	// pixels stored | b, g, r | b, g, r | b, g, r | etc.
	long pos = ((y * xsize) + x) * 3;
	
	blue = pix_buff[pos];
	green = pix_buff[pos+1];
	red = pix_buff[pos+2];
}


//////////////////////////////////////////////////////////////////////////
//
//	Write Image
//

void TGAimage::writeImage() 
{			// - pass in an array and write it to file
	
	char value;
	
	cout 	<< endl << "Creating file " << filename
			<< " (" << xsize << " x " << ysize << ")" << endl;   // display filename
	
	//unsigned char data;
	outfile.seekp(0);                           //offset 0
	//unsigned short int value = 0;
	value = 0;
	outfile.write(reinterpret_cast<const char *>(&value), sizeof(char));		//put 0  - number of chars in ID field
	outfile.seekp(1);          //offset 1
	outfile.write(reinterpret_cast<const char *>(&value), sizeof(char));		//put 0 - no color map included
	outfile.seekp(2);			 	//offset 2
	value = 2;
	outfile.write(reinterpret_cast<const char *>(&value), sizeof(char));		//put 2 - image type code
	//image specification
		outfile.seekp(8);						//offset 8
		value = 0;
		outfile.write(reinterpret_cast<const char *>(&value), sizeof(short)); // 2 bytes	//put 0 - bottom left x co-ord
		outfile.seekp(10);					//offset 10
		outfile.write(reinterpret_cast<const char *>(&value), sizeof(short));// 2 bytes		//put 0 - bottom left y co-ord
		outfile.seekp(12);
		outfile.write(reinterpret_cast<const char *>(&xsize), sizeof(short));// 2 bytes   put xsize - width of image in pixels
		outfile.seekp(14);
		outfile.write(reinterpret_cast<const char *>(&ysize), sizeof(short));// 2 bytes   put ysize - height of image in pixels
		outfile.seekp(16);
		value = 24;
		outfile.write(reinterpret_cast<const char *>(&value), sizeof(char));	   //put 24 - 24 bits per pixel
		outfile.seekp(17);
		value = 32;
		outfile.write(reinterpret_cast<const char *>(&value), sizeof(char));	//image descriptor byte
												//put 00100000 = 32 or 00000100 = 4		

	outfile.seekp(image_data_offset); 	//start of this pixel's data
	outfile.write(reinterpret_cast<const char *>(pix_buff), xsize*ysize*3*sizeof(char));

}

/////////////////////////////////////////////////////////////////////////
//
//	Blur Existing Image
//

void TGAimage::blurImage()
{
//	char r, g, b, p;
//	char br, bg, bb;
//	long pos;
	TGAimage *blur_pic;
	blur_pic = new TGAimage("blur.tga"); 
//	char* pix = (char*)calloc((xsize*ysize*3), sizeof(char));
//	char* greenpix = (char*)calloc((xsize*ysize), sizeof(char));
//	char* bluepix = (char*)calloc((xsize*ysize), sizeof(char));
	unsigned long filepos = image_data_offset;		// position of pointer in file

	
	blur_pic->createNew(xsize, ysize);

	if (!(infile.is_open()))	// if file is not open for read then return
		return;			
	
	cout << "Bluring..." << endl;

//	infile.seekg(filepos);
//	infile.read(pix, xsize*ysize*3*sizeof(char));

//	for (int y=0; y < ysize; y++)
//	{
//		if (y % 100 == 0)
//			cout << "reading line " << y << endl;

	//	for (int x=0; x < xsize; x++)   // Read values from file into arrays
//		{
		//	GetPixelColour(r, g, b, x, y);
			
			// pixels stored in this direction x ->
			// pixels colours stored blue, green, red
//			infile.seekg(filepos++); 	//start of this pixel's data
//			infile.read(&p, sizeof(char));		// read pixel's blue data
			/*infile.seekg(filepos++);
			infile.read(&g, sizeof(char));		// read pixel's green data
			infile.seekg(filepos++);
			infile.read(&r, sizeof(char));	// read pixel's red data   */

//			pos = (y*xsize)+x;
//			pix[pos] = p;
//			if (pos % 10000 == 0)
//				cout << "read in " << pos << " pixels" << endl;
			//greenpix[pos] = g;
			//bluepix[pos] = b;
//		}
//	}
	
	// COMMENTS!!
/*	for (int y=1; y < (ysize-1); y++)
	{
		if (y % 100 == 0)
			cout << "line " << y << " of " << ysize << endl;

		for (int x=1; x < (xsize-1); x++)
		{
			br = bg = bb = 0;
			// COMMENTS!!
			for (int i = -1; i < 2; i++)
				for (int j = -1; j < 2; j++)
				{
					int xi = x + i;
					int yj = y + j;
					int pos = ((yj*xsize)+xi)*3;

				//	br += redpix[pos];
				//	bg += greenpix[pos];
				//	bb += bluepix[pos];	

					br += pix[pos+2];
					bg += pix[pos+1];
					bb += pix[pos];
				}

			
			br = br / 9;
			bg = bg / 9;
			bb = bb / 9;

		
			
		}
	}*/
	blur_pic->writeImage();
	//free(pix);
}