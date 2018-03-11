#include "elements2d.h"
#include "elements3d.h"
#include "eigen3/Eigen/Dense"
#include <math.h>
using namespace std;

class projection
{
	public:
	object3d Solid;
	object2d proj;
	vector<Vertex2d> intersec_vertex;
	
	object2d project(object3d obj, vector<double> direction)
	{
		object2d obj1;
		int num_vertices = obj.vertices.size();
		int num_edges = obj.edges.size();
		for(int i = 0; i < num_vertices; i++)
		{
			obj1.vertices.push_back(project_v(obj.vertices[i]));
		}
		for(int i = 0;i < num_edges; i++)
		{
			obj1.edges.push_back(project_e(obj.edges[i]));
		}
	}
	Vertex2d project_v(Vertex3d v, vector<double> direction)
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
		v1.name = v_copy.name;
		return v1;
	}

	Edge2d project_e(Edge3d e, vector<double> direction)
	{
		///
		/// 
		///
		Edge2d e1;
		e1.v1 = project_v(e.v1, direction);
		e1.v2 = project_v(e.v2, direction);
		e1.hidden = false;
		return e1;
	}
	double rotation_angle(vector<double> direction)
	{
		double a = direction[0];
		double b = direction[1];
		double c = direction[2];
		double s2 = (a*a) + (b*b) + (c*c);
		double s = sqrt(s2);
		double costheta = c / s;
		double theta = arccosine(costheta);
		return theta;
	}

	object2d seperate(object2d s)
	{
		object2d s1;
		for (int i = 0; i < s.edges.size(); ++i)
		{
			Edge2d e1 = s.edges[i];
			for (int j = 0; j < s.edges.size(); ++j)
			{
				Edge2d e2 = s.edges[j];
				intersec_vertex.push_back(e1.v1);
				if (e1 != e2)
				{
					intersection(e1,e2);

				}
			}
			intersec_vertex.push_back(e1.v2);
			for (int i = 0; i < intersec_vertex.size()-1; ++i)
			{
				s1.edges.push_back(Edge2d(intersec_vertex[i], intersec_vertex[i+1]));
			}
	
		}
		return s1;
	}

	void intersection(Edge2d e1, Edge2d e2)
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
		if (a == (a1+a2))//also check that none of a1,a2,b1,b2 != 0
			if (b == (b1+b2))
			{
				//intersection exist
				cout<<"intersection"<<endl;
				intersec_vertex.push_back(Vertex2d(x0,y0));
				
			}
				
	}
};