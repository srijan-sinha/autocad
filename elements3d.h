#include <string>
#include <vector>
#include <iostream>
#include <math.h>
#include "eigen3/Eigen/Dense"
using Eigen::MatrixXd;
using namespace std;

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
	 	name = "";
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
		cout << "direction vector: " << endl;
		for (int i=0; i<direction.size(); i++)
       		cout << direction[i] << " ";

       	double sinx = sin(radian);
       	double cosx = cos(radian);
       	cout << endl << "sinx and cosx :" << sinx << " " << cosx << endl;
       	double u = direction[0]*direction[0] + direction[1]*direction[1] + direction[2]*direction[2];
       	double u_x = direction[0] / sqrt(u);
       	double u_y = direction[1] / sqrt(u);
       	double u_z = direction[2] / sqrt(u);
       	
       	MatrixXd R(3,3);
	    R(0,0) = cosx + (u_x*u_x)*(1-cosx);
	    R(1,0) = u_y*u_x*(1-cosx) + u_z*sinx;
	    R(0,1) = u_y*u_x*(1-cosx) - u_z*sinx;
	    R(1,1) = cosx + (u_y*u_y)*(1-cosx);
	    R(0,2) = u_z*u_x*(1-cosx) + u_y*sinx;
	    R(2,0) = u_z*u_x*(1-cosx) - u_y*sinx;
	    R(2,1) = u_z*u_y*(1-cosx) + u_x*sinx;
	    R(1,2) = u_z*u_y*(1-cosx) - u_x*sinx;
	    R(2,2) = cosx + (u_z*u_z)*(1-cosx);
	    cout << "Rotation matrix: " << endl;
	    cout << R << endl;
	    
	    MatrixXd p(3,1);
	    p(0,0) = x;
	    p(1,0) = y;
	    p(2,0) = z;
	    cout << "initial matrix: " << endl;
	    cout << p << endl;
	    
	    MatrixXd P = R*p;
	    cout << "final matrix: " << endl;
	    cout << P << endl;

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

class Edge3d
{
	public:
	Vertex3d v1, v2;
	string name;
	public:
	Edge3d (Vertex3d v1_c, Vertex3d v2_c, string e_name)
	{
		v1 = v1_c;
		v2 = v2_c;
		name = v1_c.name + v2_c.name;	
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
	
};

