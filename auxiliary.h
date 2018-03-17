#include "elements2d.h"
#include "elements3d.h"

class auxiliary
{
	public:
	void translate2d(object3d obj,vector<double> direction, double units)
	{
		obj.translate_2d(direction,units);
	}
	void mirror2d(object3d obj,int direction)
	{
		obj.mirror_2d.mirror(direction);
	}
	void rotate2d(object3d obj,double radian)
	{
		obj.rotate_2d(radian);
	}
	void scale2d(object3d obj,double factor)
	{
		obj.scale_2d(factor);
	}
	void shear2d(object3d obj,double factor, int direction) //0 for x and 1 for y;
	{
		obj.shear_2d(factor,direction);
	}
	void translate3d(object3d obj,vector<double> direction, double value)
	{
		//direction 1->x 2->y 3->z
		obj.translate_3d(direction,value);
	}
	void mirror3d(object3d obj,vector<double> plane)
	{
		//plane 1->x-y 2->y-z 3->z-x
		obj.mirror_3d(plane);
		
	}
	void rotate3d(object3d obj,vector<double> direction, double radian)
	{
		//direction protocol same as translate, degrees always clockwise
		obj.rotate_3d(direction,radian);
	}
	void scale3d(object3d obj,double factor)
	{
		//scales by input factor
		obj.scale_3d(factor);
	}
};