//#include "elements2d.h"
//#include "elements3d.h"
#include "eigen3/Eigen/Dense"
#include <math.h>
#include <vector>
using namespace std;

class projection
{
	public:
	object3d solid;
	object2d proj;
	vector<double> direction;
	// vector<Vertex2d> intersec_vertex;
	
	void project()
	{
		cout<<"solid vert:"<<endl;
		for (int i = 0; i < solid.vertices.size(); ++i)
		{
			cout<<solid.vertices[i].x<<" "<<solid.vertices[i].y<<" "<<solid.vertices[i].z<<" "<<solid.vertices[i].name<<endl;

		}
		cout<<"$$$$$";
		cout<<"direction in project:"<<endl;
		for (int i = 0; i < direction.size(); ++i)
		{
			cout<<direction[i]<<" ";

		}
		cout<<endl<<"$$$$$"<<endl;
		
		object2d obj1;
		int num_vertices = solid.vertices.size();
		int num_edges = solid.edges.size();
		cout<<"vertex in solid :"<<endl;
		for (int i = 0; i < num_vertices; ++i)
		{
			cout<<solid.vertices[i].x<<" "<<solid.vertices[i].y<<" "<<solid.vertices[i].z<<endl;
		}
		cout<<"$$$$$";
		
		cout<<"edges in solid :"<<endl;
		for (int i = 0; i < num_edges; ++i)
		{
			cout<<solid.edges[i].v1.x<<" "<<solid.edges[i].v1.y<<" "<<solid.edges[i].v1.z<<"    ";
			cout<<solid.edges[i].v2.x<<" "<<solid.edges[i].v2.y<<" "<<solid.edges[i].v2.z<<endl;
		}
		cout<<"$$$$$";
		for(int i = 0; i < num_vertices; i++)
		{
			obj1.vertices.push_back(project_v(solid.vertices[i]));
		}
		for(int i = 0;i < num_edges; i++)
		{
			obj1.edges.push_back(project_e(solid.edges[i]));
		}

		proj = obj1;
		set_bool();
	}
	Vertex2d project_v(Vertex3d v)
	{
		///
		/// Finds out the projection of a 3D vertex given a plane of projection by rotating the plane to coincide it with x-y plane.
		///	
		Vertex2d v1;

		Vertex3d v_copy = Vertex3d(v.x, v.y, v.z, v.name);
		
		double angle = rotation_angle();
		double angle_degree = angle*180/3.14;
		angle_degree = floor(10*angle_degree)/10; 
		cout<<"rotation angle :"<<angle_degree;
		angle = angle_degree*3.14/180;
		
		vector<double> rot_axis;
		if (direction[1] == 0)
			rot_axis.push_back(0);
		else
			rot_axis.push_back(-1 *direction[1]);
		rot_axis.push_back(direction[0]);
		rot_axis.push_back(0);
		cout<<"rotate axis:"<<endl;
		for (int i = 0; i < rot_axis.size(); ++i)
		{
			cout<<rot_axis[i]<<" ";

		}
		cout<<endl<<"$$$$$"<<endl;
		
		if (!(rot_axis[0] == 0 && rot_axis[1] == 0 && rot_axis[2] == 0))
		v_copy.rotate(rot_axis, angle);
		cout<<"##############################################";
		cout<<"v_copy: "<<v_copy.x<<" "<<v_copy.y<<" "<<v_copy.z<<endl;
		
		cout<<endl<<"$$$$$"<<endl;
		
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
		
		cout<<e.v1.x<<" "<<e.v1.y<<" "<<e.v1.z<<"    ";
		cout<<e.v2.x<<" "<<e.v2.y<<" "<<e.v2.z<<endl;
		Edge2d e1;
		e1.v1 = project_v(e.v1);
		e1.v2 = project_v(e.v2);
		e1.hidden = false;
		e1.proj_of = e;

		return e1;
	}

	Surface2d project_s(Surface3d s)
	{
		///
		///
		///
		Surface2d s1;
		Edge3d e;
		vector<Edge2d> edges;
		for (int i = 0; i < s.edges.size(); i++)
		{
			edges.push_back(project_e(s.edges[i]));
		}
		s1.num_edges = s.num_edges;
		s1.edges = edges;
		return s1;
	}

	double rotation_angle()
	{
		cout<<"direction in rotation_angle:"<<endl;
		for (int i = 0; i < direction.size(); ++i)
		{
			cout<<direction[i]<<" ";

		}
		cout<<endl<<"$$$$$"<<endl;
		
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
		e1.v2.length = a;
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
		for(int i = 0; i < solid.surfaces.size(); i++)
		{
			if(hid_by_surf(e, solid.surfaces[i]))
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
			if(inside(e, project_s(surface)))
				e.hidden = true;
		}
	}

	bool position_fore(Vertex3d v, Surface3d surface)
	{
		Edge3d e1 = surface.edges[1];
		Edge3d e2 = surface.edges[2];
		//find cross product of e1 and e2 to get a,b,c;
		
		vector<double> w1;
		w1.push_back(e1.v1.x - e1.v2.x);
		w1.push_back(e1.v1.y - e1.v2.y);
		w1.push_back(e1.v1.z - e1.v2.z);
		vector<double> w2;
		w2.push_back(e2.v1.x - e2.v2.x);
		w2.push_back(e2.v1.y - e2.v2.y);
		w2.push_back(e2.v1.z - e2.v2.z);
		vector<double> w3 = cross(w1,w2);
		double a = w3[0];
		double b = w3[1];
		double c = w3[2];
		double d = 0;
		d = a*(e1.v1.x) + b*(e1.v1.y) + c*(e1.v1.z);
		double k = d - a*(v.x) -b*(v.y) -c*(v.z);
		k = k / c;
		if(k > 0)
			return false;
		return true;
	}

	bool inside(Edge2d e, Surface2d surface)
	{
		if((position_vert(e.v1, surface) == 0) || (position_vert(e.v2, surface) == 0))
			return false;
		else if(position_vert(e.v1, surface)*position_vert(e.v2, surface) == 1)
			return true;
		else if(position_vert(e.v1, surface)*position_vert(e.v2, surface) == 2)
			return true;
		else
		{
			if(mid_check(e.v1, e.v2, surface) == 1)
				return true;
			else
				return false;
		}
	}

	int position_vert(Vertex2d v, Surface2d surface)
	{
		///
		/// returns 0 if vert outside, 1 if inside, 2 if on the line
		///
		if(on_boundary(v, surface))
			return 2;
		else if(ray_casting(v, surface) % 2 == 1)
			return 1;
		else if(ray_casting(v, surface) % 2 == 0)
			return 0;
		else
			cout << "Ray Casting Error" << endl;
		return 0;
	}

	bool on_boundary(Vertex2d v, Surface2d surface)
	{
		for (int i = 0; i < surface.edges.size(); i++)
		{
			if(on_edge(v, surface.edges[i]))
				return true;
		}
		return false;
	}

	bool on_edge(Vertex2d v, Edge2d e)
	{
		double x1 = e.v1.x;
		double y1 = e.v1.y;
		double x2 = e.v2.x;
		double y2 = e.v2.y;
		double d1 = sqrt((v.x-x1)*(v.x-x1) + (v.y-y1)*(v.y-y1));
		double d2 = sqrt((v.x-x2)*(v.x-x2) + (v.y-y2)*(v.y-y2));
		double d = 	sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
		if(d1 + d2 == d)
			return true;
		return false;

	}

	int ray_casting(Vertex2d v, Surface2d surface)
	{
		int count = 0;
		count = count + poly_vertex(v, surface);
		count = count + coincident_edge(v, surface);
		count = count + edge_intersect(v, surface);
		return count;
	}

	int poly_vertex(Vertex2d v, Surface2d surface)
	{
		int count = 0;
		for (int i = 0; i < surface.num_edges; i++)
		{
			if((surface.edges[i].v1.y == v.y) && (surface.edges[i].v2.y != v.y))
				count = count + check_side_vert(surface.edges[i].v1, surface);
			else if((surface.edges[i].v2.y == v.y) && (surface.edges[i].v1.y) != v.y)
				count = count + check_side_vert(surface.edges[i].v2, surface);
		}
		return (count / 2);
	}

	int coincident_edge(Vertex2d v, Surface2d surface)
	{
		int count = 0;
		for (int i = 0; i < surface.num_edges; i++)
		{
			if((surface.edges[i].v1.y == v.y) && (surface.edges[i].v2.y == v.y))
			{
				count = count + check_side_edge(surface.edges[i], surface);
			}
		}
		return count;
	}

	int edge_intersect(Vertex2d v, Surface2d surface)
	{
		int count = 0;
		for (int i = 0; i < surface.num_edges; i++)
		{
			if((surface.edges[i].v1.y > v.y) && (surface.edges[i].v2.y < v.y))
				count = count + 1;
			else if((surface.edges[i].v1.y < v.y) && (surface.edges[i].v2.y > v.y))
				count = count + 1;
		}
		return count;
	}

	int check_side_vert(Vertex2d v, Surface2d surface)
	{
		vector<int> y;
		for (int i = 0; i < surface.num_edges; i++)
		{
			if((surface.edges[i].v1.x == v.x) && (surface.edges[i].v1.y == v.y))
				y.push_back(surface.edges[i].v2.y);
			else if((surface.edges[i].v2.x == v.x) && (surface.edges[i].v2.y == v.y))
				y.push_back(surface.edges[i].v1.y);
		}
		if(y.size() != 2)
			cout << "Error check_side_vert" << endl;
		if ((y[0] - v.y)*(y[1] - v.y) < 0)
			return 1;
	}

	int check_side_edge(Edge2d e, Surface2d surface)
	{
		Vertex2d v1;
		Vertex2d v2;
		vector<int> y;
		v1.x = e.v1.x;
		v1.y = e.v1.y;
		v2.x = e.v2.x;
		v2.y = e.v2.y;

		Edge2d e1;
		for (int i = 0; i < surface.num_edges; i++)
		{
			e1 = surface.edges[i];
			if((e1.v1.x == v1.x) && (e1.v1.y == v1.y))
			{
				if(!((e1.v2.x == v2.x) && (e1.v2.y == v2.y)))
					y.push_back(v2.y);
			}
			else if((e1.v1.x == v2.x) && (e1.v1.y == v2.y))
			{
				if(!((e1.v2.x == v1.x) && (e1.v2.y == v1.y)))
					y.push_back(v1.y);
			}
			else if((e1.v2.x == v2.x) && (e1.v2.y == v2.y))
			{
				if(!((e1.v1.x == v1.x) && (e1.v1.y == v1.y)))
					y.push_back(v1.y);
			}
			else if((e1.v2.x == v1.x) && (e1.v2.y == v1.y))
			{
				if(!((e1.v1.x == v2.x) && (e1.v1.y == v2.y)))
					y.push_back(v1.y);
			}
		}
		if(y.size() != 2)
			cout << "Error check_side_edge" << endl;
		if((y[0] - v1.y)*(y[1] - v1.y) < 0)
			return 1;
	}

	int mid_check(Vertex2d v1, Vertex2d v2, Surface2d surface)
	{
		///
		/// returns the location of mid-point of v1 and v2
		///
		Vertex2d v;
		v.x = (v1.x + v2.x)/2;
		v.y = (v1.y + v2.y)/2;
		v.z = (v1.z + v2.z)/2;
		return position_vert(v, surface);
	}

	vector<double> cross(vector<double> v1, vector<double> v2)
	{
		vector<double> v3;
		v3.push_back(v1[1]*v2[2] - v1[2]*v2[1]);
		v3.push_back(v1[0]*v2[2] - v1[2]*v2[0]);
		v3.push_back(v1[0]*v2[1] - v1[1]*v2[0]);
		return v3;	
	}
};