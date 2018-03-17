#include <string>
#include <vector>
using namespace std;

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