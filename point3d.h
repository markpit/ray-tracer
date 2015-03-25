#ifndef point3d_h
#define point3d_h



//**********************************************//
//												//
//	Point3d.h - header file for 3d point class	//
//												//
//**********************************************//



class Point3d
{
	public:
		double x, y, z;		// x, y, z coords of this 3d point

		Point3d();
			//
			// Constructor 
			///////////////////////////////////////////////////////////////////////////

		Point3d(double xpos, double ypos, double zpos);
			//
			// Constructor with 3 params, sets point to xpos, ypos, zpos
			///////////////////////////////////////////////////////////////////////////

};


#endif