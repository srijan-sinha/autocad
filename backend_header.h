#include <string>
#include <vector>
#include <iostream>
#include <math.h>
#include "eigen3/Eigen/Dense"
using Eigen::MatrixXd;

using namespace std;
//////////////////////////////////Vertex3d///////////////////////////////////////////////
class Vertex3d
{
	public:
	double x, y, z;
	string name;
	public:
	Vertex3d(double x_c, double y_c, double z_c, string v_name)
	{
		x = x_c;
		y = y_c;
		z = z_c;
		name = v_name;
		
	}
	Vertex3d()
	{
	 	x = 0;
	 	y = 0;
	 	z = 0;
	 	
	}
	public: 

	void translate(vector<double> direction, double value)
	{
		//direction 1->x 2->y 3->z
		cout << "direction vector: " << endl;
		for (int i=0; i<direction.size(); i++)
       		cout << direction[i] << " ";

       	double u = direction[0]*direction[0] + direction[1]*direction[1] + direction[2]*direction[2];
       	double u_x = direction[0] / sqrt(u);
       	double u_y = direction[1] / sqrt(u);
       	double u_z = direction[2] / sqrt(u);
       	
       	MatrixXd T(3,1);
	    T(0,0) = value*u_x;
	    T(1,0) = value*u_y;
	    T(2,0) = value*u_z;

       	MatrixXd p(3,1);
	    p(0,0) = x;
	    p(1,0) = y;
	    p(2,0) = z;
	    cout << "initial matrix: " << endl;
	    cout << p << endl;
	    
	    MatrixXd P = T + p;
	    cout << "final matrix: " << endl;
	    cout << P << endl;

	    x = P(0,0);
	    y = P(1,0);
	    z = P(2,0);
	}
	void mirror(vector<double> plane)
	{
		//plane 1->x-y 2->y-z 3->z-x
		cout << "direction vector: " << endl;
		for (int i=0; i<plane.size(); i++)
       		cout << plane[i] << " ";

       	double u = plane[0]*plane[0] + plane[1]*plane[1] + plane[2]*plane[2];
       	double a = plane[0] / sqrt(u);
       	double b = plane[1] / sqrt(u);
       	double c = plane[2] / sqrt(u);
       	double d = plane[3];
       	
       	MatrixXd R(4,4);
	    R(0,0) = 1 - 2*a*a;
	    R(1,0) = -1*2*a*b;
	    R(0,1) = -1*2*a*b;
	    R(1,1) = 1 - 2*b*b;
	    R(0,2) = -1*2*a*c;
	    R(2,0) = -1*2*a*c;
	    R(2,1) = -1*2*b*c;
	    R(1,2) = -1*2*b*c;
	    R(2,2) = 1 - 2*c*c;
	    R(0,3) = -1*2*a*d;
	    R(3,0) = 0;
	    R(3,1) = 0;
	    R(1,3) = -1*2*b*d;
	    R(3,2) = 0;
	    R(2,3) = -1*2*c*d;
	    R(3,3) = 0;
	    cout << "Reflection matrix: " << endl;
	    cout << R << endl;
	    
	    MatrixXd p(4,1);
	    p(0,0) = x;
	    p(1,0) = y;
	    p(2,0) = z;
	    p(3,0) = 1;
	    cout << "initial matrix: " << endl;
	    cout << p << endl;
	    
	    MatrixXd P = R*p;
	    cout << "final matrix: " << endl;
	    cout << P << endl;

	    x = P(0,0);
	    y = P(1,0);
	    z = P(2,0);

	}
	void rotate(vector<double> direction, double radian)
	{
		//direction protocol same as translate, degrees always clockwise
		//cout << "direction vector: " << endl;
		//for (int i=0; i<direction.size(); i++)
       	//	cout << direction[i] << " ";

       	double sinx = sin(radian);
       	double cosx = cos(radian);
       //	cout << endl << "sinx and cosx :" << sinx << " " << cosx << endl;
       	double u = direction[0]*direction[0] + direction[1]*direction[1] + direction[2]*direction[2];
       	double u_x = direction[0] / sqrt(u);
       	double u_y = direction[1] / sqrt(u);
       	double u_z = direction[2] / sqrt(u);
       	//cout<<"u_x: "<<u_x<<"u_y: "<<u_y<<"u_z: "<<u_z<<endl;
       	MatrixXd R(3,3);
	    R(0,0) = cosx + (u_x*u_x)*(1-cosx);
	    R(1,0) = u_y*u_x*(1-cosx) - u_z*sinx;
	    R(0,1) = u_y*u_x*(1-cosx) + u_z*sinx;
	    R(1,1) = cosx + (u_y*u_y)*(1-cosx);
	    R(0,2) = u_z*u_x*(1-cosx) - u_y*sinx;
	    R(2,0) = u_z*u_x*(1-cosx) + u_y*sinx;
	    R(2,1) = u_z*u_y*(1-cosx) - u_x*sinx;
	    R(1,2) = u_z*u_y*(1-cosx) + u_x*sinx;
	    R(2,2) = cosx + (u_z*u_z)*(1-cosx);
	    //cout << "Rotation matrix: " << endl;
	    //cout << R << endl;
	    
	    MatrixXd p(3,1);
	    p(0,0) = x;
	    p(1,0) = y;
	    p(2,0) = z;
	    //cout << "initial matrix: " << endl;
	    //cout << p << endl;
	    
	    MatrixXd P = R*p;
	    //cout << "final matrix: " << endl;
	    //cout << P << endl;

	    x = P(0,0);
	    y = P(1,0);
	    z = P(2,0);
	}
	void scale(double factor)
	{
		//scales by input factor
		x = factor*x;
	    y = factor*y;
	    z = factor*z;
	}
};
//////////////////////////////////Edges3d///////////////////////////////////////////////
class Edge3d
{
	public:
	Vertex3d v1, v2;
	string name;
	public:
	Edge3d (Vertex3d v1_c, Vertex3d v2_c)
	{
		v1 = v1_c;
		v2 = v2_c;
		name = v1_c.name[0] + v2_c.name[0];	
	}
	Edge3d()
	{

	}
	void translate(vector<double> direction, double value)
	{
		//direction 1->x 2->y 3->z
		v1.translate(direction, value);
		v2.translate(direction, value);
			
	}
	void mirror(vector<double> plane)
	{
		//plane 1->x-y 2->y-z 3->z-x
		v1.mirror(plane);
		v2.mirror(plane);
	}
	void rotate(vector<double> direction, double radian)
	{
		//direction protocol same as translate, degrees always clockwise
		v1.rotate(direction, radian);
		v2.rotate(direction, radian);
	}
	void scale(double factor)
	{
		//scales by input factor
		v1.scale(factor);
		v2.scale(factor);
	}
	
};

class Surface3d
{
	public:
	int num_edges;
	vector<Edge3d> edges;
	Surface3d(vector<Edge3d> edges_c, int num_edges_c)
	{	
		edges = edges_c;
		num_edges = num_edges_c;
	}
	void translate(vector<double> direction, double value)
	{
		//direction 1->x 2->y 3->z
		for (int i = 0; i < edges.size(); i++)
       		edges[i].translate(direction, value);
	}
	void mirror(vector<double> plane)
	{
		//plane 1->x-y 2->y-z 3->z-x
		for (int i = 0; i < edges.size(); i++)
       		edges[i].mirror(plane);
	}
	void rotate(vector<double> direction, double radian)
	{
		//direction protocol same as translate, degrees always clockwise
		for (int i = 0; i < edges.size(); i++)
       		edges[i].rotate(direction, radian);
	}
	void scale(double factor)
	{
		//scales by input factor
		for (int i = 0; i < edges.size(); i++)
       		edges[i].scale(factor);
	}
};

class object3d
{
	public:
	vector<Vertex3d> vertices;
	vector<Edge3d> edges;
	vector<Surface3d> surfaces;
	object3d(vector<Vertex3d> vertices_c, vector<Edge3d> edges_c, vector<Surface3d> surfaces_c)
	{
		vertices = vertices_c;
		edges = edges_c;
		surfaces = surfaces_c;
	}
	object3d()
	{

	}
	void translate_3d(vector<double> direction, double value)
	{
		//direction 1->x 2->y 3->z
		for (int i = 0; i < surfaces.size(); i++)
       		surfaces[i].translate(direction, value);
	}
	void mirror_3d(vector<double> plane)
	{
		//plane 1->x-y 2->y-z 3->z-x
		for (int i = 0; i < surfaces.size(); i++)
       		surfaces[i].mirror(plane);
	}
	void rotate_3d(vector<double> direction, double radian)
	{
		//direction protocol same as translate, degrees always clockwise
		for (int i = 0; i < surfaces.size(); i++)
       		surfaces[i].rotate(direction, radian);
	}
	void scale_3d(double factor)
	{
		//scales by input factor
		for (int i = 0; i < surfaces.size(); i++)
       		surfaces[i].scale(factor);
	}
};


class Vertex2d
{
	public:
	Vertex3d proj_of;
	double x, y, z;
	double length;
	string name;

	Vertex2d(double first, double second, double third, string name_c)
	{
		x = first;
		y = second;
		z = third;
		name = name_c;
	}
	Vertex2d()
	{
		
	}
	void translate(vector<double> direction, double units)
	{
		cout << "direction vector: " << endl;
		for (int i=0; i<direction.size(); i++)
       		cout << direction[i] << " ";

       	double u = direction[0]*direction[0] + direction[1]*direction[1];
       	double u_x = direction[0] / sqrt(u);
       	double u_y = direction[1] / sqrt(u);
       	
       	MatrixXd T(2,1);
	    T(0,0) = units*u_x;
	    T(1,0) = units*u_y;
	    
       	MatrixXd p(2,1);
	    p(0,0) = x;
	    p(1,0) = y;
	    cout << "initial matrix: " << endl;
	    cout << p << endl;
	    
	    MatrixXd P = T + p;
	    cout << "final matrix: " << endl;
	    cout << P << endl;

	    x = P(0,0);
	    y = P(1,0);
	    
	}
	void mirror(int direction) //1 for x and -1 for y
	{

       	MatrixXd T(2,2);
	    T(0,0) = 1*direction;
	    T(1,0) = 0;
	    T(0,1) = 0;
	    T(1,1) = -1*direction;
	    
       	MatrixXd p(2,1);
	    p(0,0) = x;
	    p(1,0) = y;
	    cout << "initial matrix: " << endl;
	    cout << p << endl;
	    
	    MatrixXd P = T*p;
	    cout << "final matrix: " << endl;
	    cout << P << endl;

	    x = P(0,0);
	    y = P(1,0);
	}
	void rotate(double radian)
	{
		double cosx = cos(radian);
		double sinx = sin(radian);
       	MatrixXd T(2,2);
	    T(0,0) = cosx;
	    T(1,0) = -1*sinx;
	    T(0,1) = sinx;
	    T(1,1) = cosx;
	    
       	MatrixXd p(2,1);
	    p(0,0) = x;
	    p(1,0) = y;
	    cout << "initial matrix: " << endl;
	    cout << p << endl;
	    
	    MatrixXd P = T*p;
	    cout << "final matrix: " << endl;
	    cout << P << endl;

	    x = P(0,0);
	    y = P(1,0);
	}
	void scale(double factor)
	{
		x = factor*x;
		y = factor*y;
	}
	void shear(double factor, int direction) //0 for x and 1 for y;
	{
		int cx,cy;
		if (direction == 0)
			cx=1;
		else
			cy=1;
		MatrixXd T(2,2);
	    T(0,0) = 1;
	    T(1,0) = cx * factor;
	    T(0,1) = cy * factor;
	    T(1,1) = 1;
	    
       	MatrixXd p(2,1);
	    p(0,0) = x;
	    p(1,0) = y;
	    cout << "initial matrix: " << endl;
	    cout << p << endl;
	    
	    MatrixXd P = T*p;
	    cout << "final matrix: " << endl;
	    cout << P << endl;

	    x = P(0,0);
	    y = P(1,0);
	}
};

class Edge2d
{
	public:
	Vertex2d v1, v2;
	Edge3d proj_of;
	bool hidden;
	string name;
	// data of which plane?
	Edge2d (Vertex2d v1_c, Vertex2d v2_c)
	{
		v1 = v1_c;
		v2 = v2_c;
		hidden = false;
	}
	Edge2d()
	{

	}
	void translate(vector<double> direction, double units)
	{
		v1.translate(direction,units);
		v2.translate(direction,units);
	}
	void mirror(int direction)
	{
		v1.mirror(direction);
		v2.mirror(direction);
	}
	void rotate(double radian)
	{
		v1.rotate(radian);
		v2.rotate(radian);
	}
	void scale(double factor)
	{
		v1.scale(factor);
		v2.scale(factor);
	}
	void shear(double factor, int direction) //0 for x and 1 for y;
	{
		v1.shear(factor,direction);
		v2.shear(factor,direction);
	}
};

class Surface2d
{
public:
	int num_edges;
	vector<Edge2d> edges;
	Surface2d(vector<Edge2d> edges_c, int num_edges_c)
	{	
		edges = edges_c;
		num_edges = num_edges_c;
	}
	Surface2d()
	{
		
	}
	//Add functionalities.
	void translate(vector<double> direction, double units)
	{
		for (int i = 0; i < num_edges; ++i)
		{
			edges[i].translate(direction,units);
		}
	}
	void mirror(int direction)
	{
		for (int i = 0; i < num_edges; ++i)
		{
			edges[i].mirror(direction);
		}
	}
	void rotate(double radian)
	{
		for (int i = 0; i < num_edges; ++i)
		{
			edges[i].rotate(radian);
		}
	}
	void scale(double factor)
	{
		for (int i = 0; i < num_edges; ++i)
		{
			edges[i].scale(factor);
		}
	}
	void shear(double factor, int direction) //0 for x and 1 for y;
	{
		for (int i = 0; i < num_edges; ++i)
		{
			edges[i].shear(factor,direction);
		}
	}
};

class object2d
{
	public:
	vector<Vertex2d> vertices;
	vector<Edge2d> edges;
	vector<Surface2d> surfaces;
	int num_surface = surfaces.size();
	void translate_2d(vector<double> direction, double units)
	{
		for (int i = 0; i < num_surface; ++i)
		{
			surfaces[i].translate(direction,units);
		}
	}
	void mirror_2d(int direction)
	{
		for (int i = 0; i < num_surface; ++i)
		{
			surfaces[i].mirror(direction);
		}
	}
	void rotate_2d(double radian)
	{
		for (int i = 0; i < num_surface; ++i)
		{
			surfaces[i].rotate(radian);
		}
	}
	void scale_2d(double factor)
	{
		for (int i = 0; i < num_surface; ++i)
		{
			surfaces[i].scale(factor);
		}
	}
	void shear_2d(double factor, int direction) //0 for x and 1 for y;
	{
		for (int i = 0; i < num_surface; ++i)
		{
			surfaces[i].shear(factor,direction);
		}
	}
};


//////////////////////////////////auxiliary///////////////////////////////////////////////
class auxiliary
{
	public:
	void translate2d(object2d obj,vector<double> direction, double units)
	{
		obj.translate_2d(direction,units);
	}
	void mirror2d(object2d obj,int direction)
	{
		obj.mirror_2d(direction);
	}
	void rotate2d(object2d obj,double radian)
	{
		obj.rotate_2d(radian);
	}
	void scale2d(object2d obj,double factor)
	{
		obj.scale_2d(factor);
	}
	void shear2d(object2d obj,double factor, int direction) //0 for x and 1 for y;
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








class projection
{
	public:
	object3d solid;
	object2d proj;
	vector<double> direction;
	// vector<Vertex2d> intersec_vertex;
	
	void project()
	{
		cout<<"**********************************in project()"<<endl;
		cout<<"direction in project:"<<endl;
		for (int i = 0; i < direction.size(); ++i)
		{
			cout<<direction[i]<<" ";

		}
		cout<<endl<<"$$$$$"<<endl;
		
		object2d obj1;
		int num_vertices = solid.vertices.size();
		int num_edges = solid.edges.size();
		// cout<<"vertex in solid :"<<endl;
		// for (int i = 0; i < num_vertices; ++i)
		// {
		// 	cout<<solid.vertices[i].x<<" "<<solid.vertices[i].y<<" "<<solid.vertices[i].z<<endl;
		// }
		// cout<<"$$$$$";
		
		// cout<<"edges in solid :"<<endl;
		// for (int i = 0; i < num_edges; ++i)
		// {
		// 	cout<<solid.edges[i].v1.x<<" "<<solid.edges[i].v1.y<<" "<<solid.edges[i].v1.z<<"    ";
		// 	cout<<solid.edges[i].v2.x<<" "<<solid.edges[i].v2.y<<" "<<solid.edges[i].v2.z<<endl;
		// }
		// cout<<"$$$$$";
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
		//cout<<"rotation angle :"<<angle_degree;
		angle = angle_degree*3.14/180;
		
		vector<double> rot_axis;
		if (direction[1] == 0)
			rot_axis.push_back(0);
		else
			rot_axis.push_back(-1 *direction[1]);
		rot_axis.push_back(direction[0]);
		rot_axis.push_back(0);
		/*cout<<"rotate axis:"<<endl;
		for (int i = 0; i < rot_axis.size(); ++i)
		{
			cout<<rot_axis[i]<<" ";

		}
		cout<<endl<<"$$$$$"<<endl;
		*/
		if (!(rot_axis[0] == 0 && rot_axis[1] == 0 && rot_axis[2] == 0))
		v_copy.rotate(rot_axis, angle);
		//cout<<"##############################################";
		//cout<<"v_copy: "<<v_copy.x<<" "<<v_copy.y<<" "<<v_copy.z<<endl;
		
		//cout<<endl<<"$$$$$"<<endl;
		
		v1.x = v_copy.x;
		v1.y = v_copy.y;
		// cout<<"Vertex name "<<v_copy.name;
		// cout<<" z-coordinate "<<v_copy.z<<endl;
		v1.z = v_copy.z;
		v1.proj_of = v;
		v1.name = v_copy.name;
		return v1;
	}


	Edge2d project_e(Edge3d e)
	{
		///
		/// 
		///
		
		//cout<<e.v1.x<<" "<<e.v1.y<<" "<<e.v1.z<<"    ";
		//cout<<e.v2.x<<" "<<e.v2.y<<" "<<e.v2.z<<endl;
		Edge2d e1;
		e1.v1 = project_v(e.v1);
		e1.v2 = project_v(e.v2);
		e1.name = e.v1.name + e.v2.name;
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
		/*cout<<"direction in rotation_angle:"<<endl;
		for (int i = 0; i < direction.size(); ++i)
		{
			cout<<direction[i]<<" ";

		}
		cout<<endl<<"$$$$$"<<endl;
		*/
		double a = direction[0];
		double b = direction[1];
		double c = direction[2];
		double s2 = (a*a) + (b*b) + (c*c);
		double s = sqrt(s2);
		double costheta = c / s;
		double theta = acos(costheta);
		return theta;
	}

	// void seperate()
	// {
	// 	object2d s1;
	// 	for (int i = 0; i < proj.edges.size(); ++i)
	// 	{
	// 		vector<Vertex2d> intersec_vertex;
	// 		Edge2d e1 = proj.edges[i];
	// 		e1.v1.length = 0;
	// 		for (int j = 0; j < proj.edges.size(); ++j)
	// 		{
	// 			Edge2d e2 = proj.edges[j];

	// 			intersec_vertex.push_back(e1.v1);

	// 			// if (e1 != e2)
	// 			// {
	// 				intersection(e1, e2, intersec_vertex);

	// 			// }
	// 		}
	// 		intersec_vertex.push_back(e1.v2);

	// 		for (int j = 0; j < intersec_vertex.size(); ++j)
	// 		{
	// 			for (int k = j+1; k < intersec_vertex.size(); ++k)
	// 			{
	// 				if(intersec_vertex[i].length > intersec_vertex[j].length)
	// 					swap(intersec_vertex[i], intersec_vertex[j]);
	// 			}
	// 		}

	// 		for (int j = 0; j < intersec_vertex.size()-1; ++j)
	// 		{
	// 			s1.edges.push_back(Edge2d(intersec_vertex[j], intersec_vertex[j+1]));
	// 		}
	
	// 	}
	// 	proj = s1;
	// }
	void separate()
	{
		cout<<"yo"<<endl;
		vector<Edge2d> new_edges;
		// cout<<"yoo"<<endl;
		for (int i = 0; i < proj.edges.size(); i++)
		{
			cout<<"yooo "<<i<<endl;
			vector<Vertex2d> cutpoints;
			// cout<<"yoooo "<<i<<endl;
			for(int j = 0; j < proj.edges.size(); j++)
			{
				cout<<"    yooooo "<<j<<endl;
				Vertex2d v;
				// cout<<"yoooooo "<<j<<endl;
				if(i != j)
				{
					if(cut_exist(proj.edges[i], proj.edges[j]))
					{
						v = find_cut(proj.edges[i], proj.edges[j]);
						if(locate_cut(v, proj.edges[i]))
						{
							cutpoints.push_back(v);
						}
					}
				}
			}
			cout<<"**************** "<<cutpoints.size()<<endl;
			if(cutpoints.size()>0)
			{
				cout<<"chup be"<<endl;
				sort(cutpoints);
				cout<<"Chup!!"<<endl;
				create_edges(cutpoints, proj.edges[i], new_edges);
				cout<<"Thak gaya main"<<endl;
			}
			else
			{
				new_edges.push_back(proj.edges[i]);
			}
		}
		// separated.vertices = proj.vertices;
		proj.edges = new_edges;
		// separated.surfaces = proj.surfaces;
		// proj = separated;
	}

	bool cut_exist(Edge2d e1, Edge2d e2)
	{
		double x1 = e1.v1.x;
		double y1 = e1.v1.y;
		double x2 = e1.v2.x;
		double y2 = e1.v2.y;
		double x3 = e2.v1.x;
		double y3 = e2.v1.y;
		double x4 = e2.v2.x;
		double y4 = e2.v2.y;
		if(x2 != x1 && x4 != x3)
		{
			double m1 = (y2 - y1)/(x2 - x1);
			double m2 = (y4 - y3)/(x4 - x3);
			if(m1 != m2)
				return true;
		}
		if(((x2 == x1) && (x3 != x4)) || ((x2 != x1) && (x3 ==x4)))
			return true;
		return false;
	}

	Vertex2d find_cut(Edge2d e1, Edge2d e2)
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
		v.x = x0;
		v.y = y0;
		v.z = 0;
		return v;

	}

	bool locate_cut(Vertex2d v, Edge2d e)
	{
		if((v.x < e.v1.x) && (v.x > e.v2.x))
			return true;
		else if((v.x > e.v1.x) && (v.x < e.v2.x))
			return true;
		else if(e.v1.x - e.v2.x < 0.00001)
		{
			if((v.y < e.v1.y) && (v.y > e.v2.y))
				return true;
			else if((v.y > e.v1.y) && (v.y < e.v2.y))
				return true;
		}
		return false;
	}

	void sort(vector<Vertex2d> vec)
	{
		bool flag_x = false;
		double x = vec[0].x;
		for(int i = 0; i < vec.size(); i++)
		{
			if(vec[i].x - x > 0.00001)
			{
				flag_x = true;
			}
		}

		for(int i = 0; i < vec.size(); i++)
		{
			for(int j = i+1; j < vec.size(); j++)
			{
				if(flag_x)
				{
					if(vec[i].x > vec[j].x)
						swap(vec[i], vec[j]);
				}
				else
				{
					if(vec[i].y > vec[j].y)
						swap(vec[i], vec[j]);
				}
			}
		}
	}

	void create_edges(vector<Vertex2d> v, Edge2d e, vector<Edge2d> new_edges)
	{
		Vertex2d v1;
		Vertex2d v2;
		cout<<"    yo"<<endl;
		if(e.v1.x - e.v2.x < 0.00001)
		{
			if(e.v1.x < e.v2.x)
			{
				v1 = e.v1;
			}
			else
			{
				v1 = e.v2;
			}
			v2 = v[0];
		}
		else
		{
			if(e.v1.y < e.v2.y)
			{
				v1 = e.v1;
			}
			else
			{
				v1 = e.v2;
			}
			v2 = v[0];
		}
		cout<<"    Ab rona aa raha hai"<<endl;
		for(int i = 0; i < v.size() - 1; i++)
		{
			Edge2d e1;
			e1.v1 = v1;
			e1.v2 = v2;
			e1.hidden = false;

			Edge3d e2;
			Vertex3d v3;
			Vertex3d v4;
			cout<<"    Ro doon kya? "<<i<<endl;
			find_coordinates(e, v1, v3);
			find_coordinates(e, v2, v4);
			e2.v1 = v3;
			e2.v2 = v4;
			e1.proj_of = e2;

			new_edges.push_back(e1);

			v1 = v[i];
			v2 = v[i+1];
		}
		
		if(e.v1.x - e.v2.x < 0.00001)
		{
			v1 = v[v.size()];
			if(e.v1.x < e.v2.x)
			{
				v2 = e.v2;
			}
			else
			{
				v2 = e.v1;
			}
		}
		else
		{
			v1 = v[v.size()];
			if(e.v1.y < e.v2.y)
			{
				v2 = e.v2;
			}
			else
			{
				v2 = e.v1;
			}
		}

		Edge2d e1;
		e1.v1 = v1;
		e1.v2 = v2;
		e1.hidden = false;

		Edge3d e2;
		Vertex3d v3;
		Vertex3d v4;
		find_coordinates(e, v1, v3);
		find_coordinates(e, v2, v4);
		e2.v1 = v3;
		e2.v2 = v4;
		e1.proj_of = e2;

		new_edges.push_back(e1);
	}

	void find_coordinates(Edge2d e, Vertex2d v, Vertex3d v_3d)
	{
		double x, y, z;
		double x1 = e.v1.x;double y1 = e.v1.y;double x2 = e.v2.x;double y2 = e.v2.y;
		double x0 = v.x, y0 = v.y;
		double lambda;
		if(x1 - x2 > 0.00001)
		{
			lambda = (x0 - x1)/(x2 - x0);
		}
		else
		{
			lambda = (y0 - y1)/(y2 - y0);
		}
		v_3d.x = (e.proj_of.v1.x + lambda*e.proj_of.v2.x)/(1 + lambda);
		v_3d.y = (e.proj_of.v1.y + lambda*e.proj_of.v2.y)/(1 + lambda);
		v_3d.z = (e.proj_of.v1.z + lambda*e.proj_of.v2.z)/(1 + lambda);
	}

	// void intersection(Edge2d e1, Edge2d e2, vector<Vertex2d> intersec_vertex)
	// {
	// 	double x1_0 = e1.v1.x, y1_0 = e1.v1.y, x1_1 = e1.v2.x, y1_1 = e1.v2.y;
	// 	double m1, c1;
	// 	double x2_0 = e2.v1.x, y2_0 = e2.v1.y, x2_1 = e2.v2.x, y2_1 = e2.v2.y;
	// 	double m2, c2;
	// 	double x0,y0;
	// 	Vertex2d v;
		

	// 	if ((x1_0 == x1_1) && (x2_0 == x2_1))
	// 	{
	// 		//both slope is infinite
	// 		cout<<"no intersection";

	// 	}
	// 	else if ((x1_0 == x1_1) && (x2_0 != x2_1))
	// 	{
	// 		x0 = x1_0;
	// 		m2 = (y2_0 - y2_1)/(x2_0 -x2_1);
	// 		c2 = (y2_0*x2_1 - y2_1*x2_0)/(x2_1 - x2_0);
	// 		y0 = m2*x0 + c2;
	// 	}
	// 	else if ((x1_0 != x1_1) && (x2_0 == x2_1))
	// 	{
	// 		x0 = x2_0;
	// 		m1 = (y1_0 - y1_1)/(x1_0 -x1_1);
	// 		c1 = (y1_0*x1_1 - y1_1*x1_0)/(x1_1 - x1_0);
	// 		y0 = m1*x0 + c1;
	// 	}
	// 	else
	// 	{
	// 		m1 = (y1_0 - y1_1)/(x1_0 -x1_1);
	// 		c1 = (y1_0*x1_1 - y1_1*x1_0)/(x1_1 - x1_0);
	// 		m2 = (y2_0 - y2_1)/(x2_0 -x2_1);
	// 		c2 = (y2_0*x2_1 - y2_1*x2_0)/(x2_1 - x2_0);
	// 		if (m1==m2)
	// 		{
	// 			cout<<"no intersection"<<endl;
	// 		}
	// 		else
	// 		{
	// 			x0 = (c2-c1)/(m1-m2);
	// 			y0 = (m1*c2 - c1*m2)/(m1-m2);
	// 		}

	// 	}		

			
	// 	double a,b,a1,a2,b1,b2;
	// 	a = sqrt((y1_0-y1_1)*(y1_0-y1_1) + (x1_0-x1_1)*(x1_0-x1_1));
	// 	b = sqrt((y2_0-y2_1)*(y2_0-y2_1) + (x2_0-x2_1)*(x2_0-x2_1));
	// 	a1 = sqrt((y1_0-y0)*(y1_0-y0) + (x1_0-x0)*(x1_0-x0));
	// 	a2 = sqrt((y0-y1_1)*(y0-y1_1) + (x0-x1_1)*(x0-x1_1));
	// 	b1 = sqrt((y0-y2_1)*(y0-y2_1) + (x0-x2_1)*(x0-x2_1));
	// 	b2 = sqrt((y2_0-y0)*(y2_0-y0) + (x2_0-x0)*(x2_0-x0));
	// 	v.length = a1;
	// 	e1.v2.length = a;
	// 	v.x = x0;
	// 	v.y = y0;
	// 	v.z = 0;
	// 	v.name = "";
	// 	if (a == (a1+a2))//also check that none of a1,a2,b1,b2 != 0
	// 		if (b == (b1+b2))
	// 		{
	// 			//intersection exist
	// 			cout<<"intersection"<<endl;
	// 			intersec_vertex.push_back(v);
				
	// 		}
				
	// }

	void set_bool()
	{
		separate();
		for(int i = 0; i < proj.vertices.size(); i++)
		{
			cout<<solid.vertices[i].name<<" "<<solid.vertices[i].x<<" "<<solid.vertices[i].y<<" "<<solid.vertices[i].z<<endl;
		}
		cout<<"Edges of the projection without setting hidden"<<endl<<endl;
		for (int i = 0; i < proj.edges.size(); ++i)
		{
			cout<<proj.edges[i].v1.x<<" "<<proj.edges[i].v1.y<<" "<<proj.edges[i].v1.z<<"   "<<proj.edges[i].v2.x<<" "<<proj.edges[i].v2.y<<" "<<proj.edges[i].v2.z<<"   "<<proj.edges[i].hidden<<" "<<proj.edges[i].name<<endl;
		}
		// cout<<endl<<position_fore(solid.vertices[13], solid.surfaces[6])<<endl;
		// int i = 20;
		for(int i = 0; i < proj.edges.size(); i++)
		{
			cout<<endl<<"checking edge: "<<proj.edges[i].v1.x<<" "<<proj.edges[i].v1.y<<" "<<proj.edges[i].v1.z<<"   "<<proj.edges[i].v2.x<<" "<<proj.edges[i].v2.y<<" "<<proj.edges[i].v2.z<<"   "<<proj.edges[i].hidden<<" "<<proj.edges[i].name<<endl;
			if (proj.edges[i].hidden == false)
				proj.edges[i].hidden=check_hidden(proj.edges[i]);
			cout<<endl<<"output edge: "<<proj.edges[i].v1.x<<" "<<proj.edges[i].v1.y<<" "<<proj.edges[i].v1.z<<"   "<<proj.edges[i].v2.x<<" "<<proj.edges[i].v2.y<<" "<<proj.edges[i].v2.z<<"   "<<proj.edges[i].hidden<<" "<<proj.edges[i].name<<endl;
			cout<<"**********************************************************************"<<endl;
		}
	}

	bool check_hidden(Edge2d e)
	{
		// int i = 6;
		for(int i = 0; i < solid.surfaces.size(); i++)
		{
			// cout<<"surface used:"<<endl;
			// 	for (int j = 0; j < solid.surfaces[i].edges.size(); ++j)
			// 	{
			// 		cout<<solid.surfaces[i].edges[j].v1.x<<" "<<solid.surfaces[i].edges[j].v1.y<<" "<<solid.surfaces[i].edges[j].v1.z<<"   ";
			// 		cout<<solid.surfaces[i].edges[j].v2.x<<" "<<solid.surfaces[i].edges[j].v2.y<<" "<<solid.surfaces[i].edges[j].v2.z<<"   ";
			// 		cout<<solid.surfaces[i].edges[j].name<<endl;
			// 	}
			// 	cout<<"$$$$$"<<endl;
			if(hid_by_surf(e, solid.surfaces[i]))
			{
				cout<<"surface used:"<<endl;
				for (int j = 0; j < solid.surfaces[i].edges.size(); ++j)
				{
					cout<<solid.surfaces[i].edges[j].v1.x<<" "<<solid.surfaces[i].edges[j].v1.y<<" "<<solid.surfaces[i].edges[j].v1.z<<"   ";
					cout<<solid.surfaces[i].edges[j].v2.x<<" "<<solid.surfaces[i].edges[j].v2.y<<" "<<solid.surfaces[i].edges[j].v2.z<<"   ";
					cout<<solid.surfaces[i].edges[j].name<<endl;
				}
				cout<<"$$$$$"<<endl;
				return true;
				
			}
		}
		return false;
	}

	bool hid_by_surf(Edge2d e, Surface3d surface)
	{
		cout<<"&&&&&&&&&&&&"<<endl;
		
		Vertex3d v1 = e.proj_of.v1;
		Vertex3d v2 = e.proj_of.v2;
		// cout<<"Position_fore result "<<position_fore(v1, surface)<<" "<<position_fore(v2, surface)<<endl;
		// cout<<"Vertex1 "<<v1.x<<" "<<v1.y<<" "<<v1.z<<endl;
		
		if(position_fore(v1, surface) && position_fore(v2, surface))
		{
			//e.hidden = false;
			cout<<"v1 ahead v2 ahead"<<endl;
			return false;
		}
		else if(position_fore(v1, surface))
		{
			//e.hidden = false;
			cout<<"v1 ahead v2 back"<<endl;
			return false;
		}
		else if(position_fore(v2, surface))
		{
			cout<<"v1 back v2 ahead"<<endl;
			//e.hidden = false;
			return false;
		}	
		else
		{
			cout<<"v1 back v2 back"<<endl;
			// cout<<"Calling inside"<<endl;
			// cout<<"***************************************************"<<endl;
			if(inside(e, project_s(surface))) 
			{
				//e.hidden = true;
				cout<<"Inside success"<<endl;
				// cout<<"*****************************************************"<<endl;
				return true;
				
			}
			else
				return false;
		}
	}

	bool position_fore(Vertex3d v, Surface3d surface)
	{
		Edge3d e1 = surface.edges[1];
		Edge3d e2 = surface.edges[2];
		//find cross product of e1 and e2 to get a,b,c;
		/*cout<<"vector e1: ";
		cout<<e1.v1.x<<" "<<e1.v1.y<<" "<<e1.v1.z<<"    ";
		cout<<e1.v2.x<<" "<<e1.v2.y<<" "<<e1.v2.z<<endl;


		cout<<"vector e2: ";
		cout<<e2.v1.x<<" "<<e2.v1.y<<" "<<e2.v1.z<<"    ";
		cout<<e2.v2.x<<" "<<e2.v2.y<<" "<<e2.v2.z<<endl;
		*/
		vector<double> w1;
		w1.push_back(e1.v1.x - e1.v2.x);
		w1.push_back(e1.v1.y - e1.v2.y);
		w1.push_back(e1.v1.z - e1.v2.z);
		/*cout<<"w1 :"<<endl;
		for (int i = 0; i < w1.size(); ++i)
		{
			cout<<w1[i];
		}
		cout<<"&&&&&"<<endl;
		*/
		vector<double> w2;
		w2.push_back(e2.v1.x - e2.v2.x);
		w2.push_back(e2.v1.y - e2.v2.y);
		w2.push_back(e2.v1.z - e2.v2.z);
		/*cout<<"w2 :"<<endl;
		for (int i = 0; i < w2.size(); ++i)
		{
			cout<<w2[i];
		}
		cout<<"&&&&&"<<endl;
		*/
		vector<double> w3 = cross(w1,w2);
		/*cout<<"w3 :"<<endl;
		for (int i = 0; i < w3.size(); ++i)
		{
			cout<<w3[i];
		}
		cout<<"&&&&&"<<endl;
		*/
		double a = w3[0];
		double b = w3[1];
		double c = w3[2];
		double d = 0;
		//cout<<"a = "<<a<<" b = "<<b<<" c = "<<c<<endl;
		d = (a*(e1.v1.x) + b*(e1.v1.y) + c*(e1.v1.z));
		// cout<<"d = "<<d<<" c = "<<c<<" a = "<<a<<" b = "<<b<<endl;
		if ((a*direction[0] + b*direction[1] + c*direction[2]) == 0)
			return true;
		double k = (d - a*(v.x) -b*(v.y) -c*(v.z))/(a*direction[0] + b*direction[1] + c*direction[2]);
		// cout<<v.name<<endl;
		// cout<<"k = "<<k<<endl;
		if(k > 0)
			return true;
		return false;
	}

	bool inside(Edge2d e, Surface2d surface)
	{
		//cout<<"vector e: ";
		//cout<<e.v1.x<<" "<<e.v1.y<<" "<<e.v1.z<<"    ";
		//cout<<e.v2.x<<" "<<e.v2.y<<" "<<e.v2.z<<endl;
		// cout<<"Position_vert results "<<position_vert(e.v1, surface)<<" "<<position_vert(e.v2, surface)<<endl;
		if((position_vert(e.v1, surface) == 0) || (position_vert(e.v2, surface) == 0))
			return false;
		else if(position_vert(e.v1, surface)*position_vert(e.v2, surface) == 1)
			return true;
		else if(position_vert(e.v1, surface)*position_vert(e.v2, surface) == 2)
			return true;
		else
		{
			// cout<<"    Calling mid_check"<<endl;
			// cout<<"    ****************************************************"<<endl;
			if(mid_check(e.v1, e.v2, surface) == 1)
			{
				// cout<<"mid-check valid "<<endl;
				// cout<<"    ****************************************************"<<endl;
				return true;
			}
			else
			{
				// cout<<"    mid-check not valid "<<endl;
				// cout<<"    ****************************************************"<<endl;
					
				return false;
			}
		}
	}

	int position_vert(Vertex2d v, Surface2d surface)
	{
		///
		/// returns 0 if vert outside, 1 if inside, 2 if on the line
		///
		/*cout<<"surface edges:"<<endl;
		for (int i = 0; i < surface.edges.size(); ++i)
		{
			cout<<surface.edges[i].v1.x<<" "<<surface.edges[i].v1.y<<" "<<surface.edges[i].v1.z<<"    ";
			cout<<surface.edges[i].v2.x<<" "<<surface.edges[i].v2.y<<" "<<surface.edges[i].v2.z<<endl;
		
		}*/
		// cout<<"Ray Casting result of "<<v.name<<" "<<ray_casting(v,surface)<<endl;
		// cout<<"////////////////////////////////////"<<endl;
		// cout<<"        Calling on boundary"<<endl;
		// cout<<"        ****************************************************"<<endl;
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
		// cout<<v.name<<" "<<v.x<<"  "<<v.y<<endl;
		for (int i = 0; i < surface.edges.size(); i++)
		{
			// cout<<"            Calling on edge for edge "<<i<<endl;
			// cout<<"            ****************************************************"<<endl;
			if(on_edge(v, surface.edges[i]))
			{
				// cout<<"Vertex "<<v.name<<" "<<v.x<<" "<<v.y<<endl;
				// cout<<"On edge "<<surface.edges[i].name<<endl;
				return true;
			}
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
		// cout<<"//////////////"<<endl;
		// cout<<"                For "<<e.name<<" d = "<<d<<endl;
		// cout<<"                d1 + d2 = "<<d1+d2<<endl;
		if(abs(d1 + d2 - d) < 0.00001)
		{
			// cout<<"                Yayyyyyyyyyyyyyyyyyy"<<endl;
			return true;
		}
		return false;

	}

	int ray_casting(Vertex2d v, Surface2d surface)
	{
		int count = 0;
		//cout<<"count initial: "<<count<<endl;
		count = count + poly_vertex(v, surface);
		// cout<<"Count after poly vertex "<<count<<endl;
		//cout<<"count after poly_vertex: "<<count<<endl;
		count = count + coincident_edge(v, surface);
		// cout<<"Count after coincident edge "<<count<<endl;
		//cout<<"count after coincident_edge: "<<count<<endl;
		count = count + edge_intersect(v, surface);
		// cout<<"Count after edge intersect "<<count<<endl;
		// cout<<"Hence: "<<endl;
		//cout<<"count edge_intersect: "<<count<<endl;
		return count;
	}

	int poly_vertex(Vertex2d v, Surface2d surface)
	{
		int count = 0;
		for (int i = 0; i < surface.num_edges; i++)
		{
			if((surface.edges[i].v1.y == v.y) && (surface.edges[i].v2.y!= v.y))
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
			double x0 = surface.edges[i].v1.x + (v.y - surface.edges[i].v1.y)*(surface.edges[i].v2.x - surface.edges[i].v1.x)/(surface.edges[i].v2.y - surface.edges[i].v1.y); 
			if (x0>v.x)
			{
				if((surface.edges[i].v1.y > v.y) && (surface.edges[i].v2.y < v.y))
					count = count + 1;
				else if((surface.edges[i].v1.y < v.y) && (surface.edges[i].v2.y > v.y))
					count = count + 1;
			}
			if(i==0 || i==2)
			{
				// cout<<"Edge "<<"v1 = "<<surface.edges[i].v1.x<<" "<<surface.edges[i].v1.y<<" "<<surface.edges[i].v1.z<<" v2 = "<<surface.edges[i].v2.x<<" "<<surface.edges[i].v2.y<<" "<<surface.edges[i].v2.z<<" "<<surface.edges[i].name<<endl;
				// cout<<"Vertex "<<"x "<<v.x<<" y "<<v.y<<endl;
				// cout<<"Solution x "<<x0<<endl;
			}
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
		v.name = "MID";
		// if(v1.name=="E" && v2.name=="A")
		// {
		// 	cout<<endl<<v1.name<<" "<<v1.x<<" "<<v1.y<<endl;
			// cout<<v.name<<" "<<v.x<<" "<<v.y<<endl;
		// 	cout<<v2.name<<" "<<v2.x<<" "<<v2.y<<endl<<endl;
		// 	cout<<"Surface "<<surface.edges[1].name<<" "<<surface.edges[1].v1.x<<" "<<surface.edges[1].v1.y<<" "<<surface.edges[1].v2.x<<" "<<surface.edges[1].v2.y<<endl;
		// }
		//cout<<"in mid_check: "<<position_vert(v,surface)<<endl;
		// if(on_boundary(v,surface))
			// return 
		// cout<<"Position of midpoint "<<position_vert(v, surface)<<endl;
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


class rev_3dto2d
{
	public:
	object3d reconstruct3d(object2d obj1, object2d obj2, object2d obj3)
	{
		
	}
	vector<Vertex3d> cor_vertex(object2d obj1, object2d obj2, object2d obj3)//obj1: x-y, obj2: y-z, obj3: x-z;
	{
		vector<Vertex2d> set1 = obj1.vertices;
		vector<Vertex2d> set2 = obj2.vertices;
		vector<Vertex2d> set3 = obj3.vertices;
		vector<Vertex2d> v1_i,v1_j;
		vector<Vertex3d> v2;
		/*cout<<"set1 is : ";
		for (int i = 0; i < set1.size(); ++i)
		{
			cout<<set1[i].x<<","<<set1[i].y<<","<<set1[i].z<<","<<set1[i].name<<endl;
		}
		cout<<"$$$$"<<endl;
		cout<<"set2 is : ";
		for (int i = 0; i < set2.size(); ++i)
		{
			cout<<set2[i].x<<","<<set2[i].y<<","<<set2[i].z<<","<<set2[i].name<<endl;
		}
		cout<<"$$$$"<<endl;*/
		for (int i = 0; i < set1.size(); ++i)
		{
			int j = find(set2,set1[i]);
			if (j != -1)
			{
				v1_i.push_back(set1[i]);
				//cout<<"j :"<<j;
				v1_j.push_back(set2[j]);
			}
		}

		/*cout<<"v1_i is : ";
		for (int i = 0; i < v1_i.size(); ++i)
		{
			cout<<v1_i[i].x<<","<<v1_i[i].y<<","<<v1_i[i].z<<","<<v1_i[i].name<<endl;
		}
		cout<<"$$$$"<<endl;

		cout<<"v1_j is : ";
		for (int i = 0; i < v1_j.size(); ++i)
		{
			cout<<v1_j[i].x<<","<<v1_j[i].y<<","<<v1_j[i].z<<","<<v1_j[i].name<<endl;
		}
		cout<<"$$$$"<<endl;*/
		for (int i = 0; i < v1_i.size(); ++i)
		{
			int j = find(set3,v1_i[i]);
			if (j != -1)
			{
				Vertex3d v;
				v.x = v1_i[i].x;
				v.y = v1_i[i].y;
				v.z = set3[j].z;
				v.name = v1_i[i].name;
				v2.push_back(v);
			}
		}
		return v2;
	}

	
	vector<Edge3d> cor_edges(object2d obj1, object2d obj2, object2d obj3 , vector<Vertex3d> vert)
	{
		vector<Edge3d> v;
		vector<double> x_y;
		vector<double> y_z;
		vector<double> x_z;
	
		x_y.push_back(0);
		x_y.push_back(0);
		x_y.push_back(1);
	
		y_z.push_back(1);
		y_z.push_back(0);
		y_z.push_back(0);
		
		x_z.push_back(0);
		x_z.push_back(1);
		x_z.push_back(0);
					
		for (int i = 0; i < vert.size(); ++i)
		{
			Vertex3d s1 = vert[i];
			for (int j = 0; j < vert.size(); ++j)
			{
				if (i!=j)
				{
					Vertex3d s2 = vert[j];
					projection p;
					Edge3d e = Edge3d(s1,s2);
					p.direction = x_y;
					Edge2d e_xy = p.project_e(e);
					int index_xy = find_edge(obj1.edges, e_xy);
					p.direction = y_z;
					Edge2d e_yz = p.project_e(e);
					int index_yz = find_edge(obj2.edges, e_yz);
					p.direction = x_z;
					Edge2d e_xz = p.project_e(e);
					int index_xz = find_edge(obj3.edges, e_xz);
					if (!(index_xz == -1 || index_yz == -1 || index_xy == -1))
					{
						//correct edge
						Edge3d e;
						e.v1 = s1;
						e.v2 = s2;
						v.push_back(e);
					}
				}
			}
		}
		return v;
	}

	int find(vector<Vertex2d> set, Vertex2d s)
	{
		/*cout<<"set is : ";
		for (int i = 0; i < set.size(); ++i)
		{
			cout<<set[i].x<<","<<set[i].y<<","<<set[i].z<<","<<set[i].name<<endl;
		}
		cout<<"$$$$"<<endl;
		cout<<"s is "<<s.name;*/
		for (int i = 0; i < set.size(); ++i)
		{
			string s1 = set[i].name; 
			//cout<<" s1 is "<<s1<<endl;
			//cout<<"condition :"<<(s1.compare(s.name)==0)<<endl;
			if (s1.compare(s.name)==0)
				return i;

		}
		return -1;
	}

	int find_edge(vector<Edge2d> set, Edge2d s)
	{
		for (int i = 0; i < set.size(); ++i)
		{
			string s1 = set[i].name; 
			//if ((s1.compare(s.name)) && (set[i].v1 == s.v1) && (set[i].v2 == s.v2))  
				return i;

		}
		return -1;
	}

	
};