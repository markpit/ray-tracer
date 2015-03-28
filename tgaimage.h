#ifndef tgaimage_h
#define tgaimage_h

/********************************************************************************/
/**                                                                            **/
/** TGAimage objects create a TGA image file that can then be written to using **/
/** the PutPixel function.													   **/
/**																			   **/
/********************************************************************************/

#include <fstream>
#include <string.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

class TGAimage {

private:
    char* filename;	   // name of TGA output file
    short xsize, ysize;  // size of image in pixels - short = 2 bytes
    ofstream outfile;  // file object for output
    ifstream infile;   // file object for input
    unsigned long image_data_offset;  // offset of image data in file (bytes)
    char* pix_buff;	// buffer - array of pixel values r,g,b or b,g,r

public:

    TGAimage(char* name);
    //
    // Constructor
    /////////////////////////////////////////////////////////////////////////

    ~TGAimage();
    //
    // Deconstructor
    /////////////////////////////////////////////////////////////////////////

    void createNew(int x, int y);
    //
    // Create New  : 'Initialises' the current image associated with this
    //				  object ready for writing to. Effectively creating a new
    //				  image.
    /////////////////////////////////////////////////////////////////////////

    void readImage();
    //
    // Read Image
    /////////////////////////////////////////////////////////////////////////

    void setPixel(char red, char green, char blue, int x, int y);
    //
    // Set Colour Of Pixel x,y
    /////////////////////////////////////////////////////////////////////////

    void getPixel(int& red, int& green, int& blue, int x, int y);
    //
    // Get Pixel Colour: pass r,g,b by reference and read values from file,
    //					 put them in r,g,b
    ////////////////////////////////////////////////////////////////////////

    void writeImage();
    //
    // Writes image from memory to disk
    /////////////////////////////////////////////////////////////////////////

    void blurImage();
    //
    // Blurs Image
    /////////////////////////////////////////////////////////////////////////
};

#endif
