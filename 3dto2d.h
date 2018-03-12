#include "elements2d.h"
#include "elements3d.h"
#include "eigen3/Eigen/Dense"
#include <math.h>
#include <vector>
using namespace std;

class projection
{
	public:
	object3d solid;
	object2d proj;
	vector<double> direction
	// vector<Vertex2d> intersec_vertex;
	
	void project()
	{
		object2d obj1;
		int num_vertices = solid.vertices.size();
		int num_edges = solid.edges.size();
		for(int i = 0; i < num_vertices; i++)
		{
			obj1.vertices.push_back(project_v(solid.vertices[i], direction));
		}
		for(int i = 0;i < num_edges; i++)
		{
			obj1.edges.push_back(project_e(solid.edges[i], direction));
		}
		proj = obj1;
	}
	Vertex2d project_v(Vertex3d v)
	{
		///
		/// Finds out the projection of a 3D vertex given a plane of projection by rotating the plane to coincide it with x-y plane.
		///	
		Vertex2d v1;
		Vertex3d v_copy = Vertex3d(v.x, v.y, v.z, v.name);
		double angle = rotation_angle(direction);
		vector<double> rot_axis;
		rot_axis.push_back(direction[1]);
		rot_axis.push_back(-1 * direction[0]);
		rot_axis.push_back(0);
		v_copy.rotate(rot_axis, angle);
		v1.x = v_copy.x;
		v1.y = v_copy.y;
		v1.z = 0;
		v1.proj_of = v;
		v1.name = v_copy.name;
		return v1;
	}

	Edge2d project_e(Edge3d e)
	{
		///
		/// 
		///
		Edge2d e1;
		e1.v1 = project_v(e.v1, direction);
		e1.v2 = project_v(e.v2, direction);
		e1.hidden = false;
		e1.proj_of = e;
		return e1;
	}
	double rotation_angle()
	{
		double a = direction[0];
		double b = direction[1];
		double c = direction[2];
		double s2 = (a*a) + (b*b) + (c*c);
		double s = sqrt(s2);
		double costheta = c / s;
		double theta = acos(costheta);
		return theta;
	}

	void seperate()
	{
		object2d s1;
		for (int i = 0; i < proj.edges.size(); ++i)
		{
			vector<Vertex2d> intersec_vertex;
			Edge2d e1 = proj.edges[i];
			e1.v1.length = 0;
			for (int j = 0; j < proj.edges.size(); ++j)
			{
				Edge2d e2 = proj.edges[j];

				intersec_vertex.push_back(e1.v1);

				// if (e1 != e2)
				// {
					intersection(e1, e2, intersec_vertex);

				// }
			}
			intersec_vertex.push_back(e1.v2);

			for (int j = 0; j < intersec_vertex.size(); ++j)
			{
				for (int k = j+1; k < intersec_vertex.size(); ++k)
				{
					if(intersec_vertex[i].length > intersec_vertex[j].length)
						swap(intersec_vertex[i], intersec_vertex[j]);
				}
			}

			for (int j = 0; j < intersec_vertex.size()-1; ++j)
			{
				s1.edges.push_back(Edge2d(intersec_vertex[j], intersec_vertex[j+1]));
			}
	
		}
		proj = s1;
	}

	void intersection(Edge2d e1, Edge2d e2, vector<Vertex2d> intersec_vertex)
	{
		double x1_0 = e1.v1.x, y1_0 = e1.v1.y, x1_1 = e1.v2.x, y1_1 = e1.v2.y;
		double m1, c1;
		double x2_0 = e2.v1.x, y2_0 = e2.v1.y, x2_1 = e2.v2.x, y2_1 = e2.v2.y;
		double m2, c2;
		double x0,y0;
		Vertex2d v;
		

		if ((x1_0 == x1_1) && (x2_0 == x2_1))
		{
			//both slope is infinite
			cout<<"no intersection";

		}
		else if ((x1_0 == x1_1) && (x2_0 != x2_1))
		{
			x0 = x1_0;
			m2 = (y2_0 - y2_1)/(x2_0 -x2_1);
			c2 = (y2_0*x2_1 - y2_1*x2_0)/(x2_1 - x2_0);
			y0 = m2*x0 + c2;
		}
		else if ((x1_0 != x1_1) && (x2_0 == x2_1))
		{
			x0 = x2_0;
			m1 = (y1_0 - y1_1)/(x1_0 -x1_1);
			c1 = (y1_0*x1_1 - y1_1*x1_0)/(x1_1 - x1_0);
			y0 = m1*x0 + c1;
		}
		else
		{
			m1 = (y1_0 - y1_1)/(x1_0 -x1_1);
			c1 = (y1_0*x1_1 - y1_1*x1_0)/(x1_1 - x1_0);
			m2 = (y2_0 - y2_1)/(x2_0 -x2_1);
			c2 = (y2_0*x2_1 - y2_1*x2_0)/(x2_1 - x2_0);
			if (m1==m2)
			{
				cout<<"no intersection"<<endl;
			}
			else
			{
				x0 = (c2-c1)/(m1-m2);
				y0 = (m1*c2 - c1*m2)/(m1-m2);
			}

		}		

			
		double a,b,a1,a2,b1,b2;
		a = sqrt((y1_0-y1_1)*(y1_0-y1_1) + (x1_0-x1_1)*(x1_0-x1_1));
		b = sqrt((y2_0-y2_1)*(y2_0-y2_1) + (x2_0-x2_1)*(x2_0-x2_1));
		a1 = sqrt((y1_0-y0)*(y1_0-y0) + (x1_0-x0)*(x1_0-x0));
		a2 = sqrt((y0-y1_1)*(y0-y1_1) + (x0-x1_1)*(x0-x1_1));
		b1 = sqrt((y0-y2_1)*(y0-y2_1) + (x0-x2_1)*(x0-x2_1));
		b2 = sqrt((y2_0-y0)*(y2_0-y0) + (x2_0-x0)*(x2_0-x0));
		v.length = a1;
		e1.v2.length = a
		v.x = x0;
		v.y = y0;
		v.z = 0;
		v.name = "";
		if (a == (a1+a2))//also check that none of a1,a2,b1,b2 != 0
			if (b == (b1+b2))
			{
				//intersection exist
				cout<<"intersection"<<endl;
				intersec_vertex.push_back(v);
				
			}
				
	}

	void set_bool()
	{
		for(int i = 0; i < proj.edges.size(); i++)
		{
			check_hidden(proj.edges[i]);
		}
	}

	void check_hidden(Edge2d e)
	{
		for(int i = 0; i < solid.surfaces.length; i++)
		{
			if(hid_by_surf(e, solid.surfaces[i])
			{
				e.hidden = true;
				break;
			}
		}
	}

	bool hid_by_surf(Edge2d e, Surface3d surface)
	{
		Vertex3d v1 = e.proj_of.v1;
		Vertex3d v2 = e.proj_of.v2;
		if(position_fore(v1, surface) && position_fore(v2, surface))
			e.hidden = false;
		else if(position_fore(v1, surface))
			e.hidden = false;
		else if(position_fore(v2, surface))
			e.hidden = true;
		else
		{
			if(inside(e, surface))
				e.hidden = true;
		}
	}

	bool position_fore(Vertex3d v, Surface3d surface)
	{
		Edge3d e1 = surface[1];
		Edge3d e2 = surface[2];
		double a = ;
		double b = ;
		double c = ;
		double d = 0;
		Vector3d v((e1.v1.x - e1.v2.x), (e1.v1.y - e1.v2.y), (e1.v1.z - e1.v2.z));
		Vector3d w((e2.v1.x - e2.v2.x), (e2.v1.y - e2.v2.y), (e2.v1.z - e2.v2.z));
		v.cross(w);
		d = a*(e1.v1.x) + b*(e1.v1.y) + c*(e1.v1.z);
		double k = d - a*(v.x) -b*(v.y) -c*(v.z);
		k = k / c;
		if(k > 0)
			return false;
		return true;
	}

	bool inside(Edge2d e, Surface3d surface)
	{

	}
};