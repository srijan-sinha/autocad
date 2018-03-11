#include "elements2d.h"
#include "elements3d.h"
#include "eigen3/Eigen/Dense"
using namespace std;

class projection
{
	public:
	object3d Solid;
	object2d proj;
	object2d project(object3d obj, int plane)
	{

	}
	Vertex2d project_v(Vertex3d v, int plane)
	{
		///
		/// Finds out the projection of a 3D vertex given a plane of projection
		///
		Vertex2d v1;
		v1.x = v.x;
		v1.y = v.y;
		v1.z = v.z;
		v1.name = v.name;
		v1.plane = plane;
		if(plane == 1)
		{
			v1.z = 0;
		}
		else if (plane == 2)
		{
			v1.x = 0;
		}
		else if (plane == 3)
		{
			v1.y = 0;
		}
		return v1;
	}

	Edge2d project_e(Edge3d e, int plane)
	{
		Edge2d e1;
		e1.v1 = projection::project_v(e.v1, plane);
		e1.v2 = projection::project_v(e.v2, plane);
		e1.plane = plane;
		e1.hidden = false;
	}
};
int main()
{

}