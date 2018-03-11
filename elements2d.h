#include <string>
using namespace std;

class Vertex2d
{
	public:
	float x, y, z;
	int plane; //1->x-y 2->y-z 3->z-x
	string name;

	Vertex2d(int first, int second){}
	Vertex2d(int arr[]){}
	Vertex2d(){}
	void translate(int direction, int units)
	{

	}
	void mirror(int plane)
	{

	}
	void rotate(int direction, int degrees)
	{

	}
	void scale(float factor)
	{

	}
};

class Edge2d
{
	public:
	Vertex2d v1, v2;
	int plane;
	bool hidden;
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

class object2d
{
	public:
	Vertex2d vertices[100];
	Edge2d edges[100];
};

