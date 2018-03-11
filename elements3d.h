#include <string>
using namespace std;

class Vertex3d
{
	public:
	float x, y, z;
	string name;
	public:
	Vertex3d(int x_c, int y_c, int z_c){x = x_c; y = y_c; z = z_c;}
	Vertex3d(){ x = 0; y = 0; z = 0;}
	public: void translate(int direction, float value)
	{
		//direction 1->x 2->y 3->z
	}
	void mirror(int plane)
	{
		//plane 1->x-y 2->y-z 3->z-x
	}
	void rotate(int direction, int degrees)
	{
		//direction protocol same as translate, degrees always clockwise
	}
	void scale(float factor)
	{
		//scales by input factor
	}
};

class Edge3d
{
	public:
	Vertex3d v1, v2;
	void translate(int direction, float value)
	{
		//direction 1->x 2->y 3->z
	}
	void mirror(int plane)
	{
		//plane 1->x-y 2->y-z 3->z-x
	}
	void rotate(int direction, int degrees)
	{
		//direction protocol same as translate, degrees always clockwise
	}
	void scale(float factor)
	{
		//scales by input factor
	}
	void projection(int plane)
	{
		//plane protocol same as mirror
	}
};

class Surface3d
{
	public:
	int num_edges;
	Edge3d arr[100];
	void translate(int direction, float value)
	{
		//direction 1->x 2->y 3->z
	}
	void mirror(int plane)
	{
		//plane 1->x-y 2->y-z 3->z-x
	}
	void rotate(int direction, int degrees)
	{
		//direction protocol same as translate, degrees always clockwise
	}
	void scale(float factor)
	{
		//scales by input factor
	}
};

class object3d
{
	public:
	Vertex3d vertices[100];
	Edge3d edges[100];
	Surface3d surfaces[100];
};

