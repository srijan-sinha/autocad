#include "elements2d.h"
#include "elements3d.h"

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
		vector<Vertex2d> v1;
		vector<Vertex3d> v2;
		
		for (int i = 0; i < set1.size(); ++i)
		{
			int j = find(set2,set1[i]);
			if (j != -1)
			{
				v1.push_back(set1[i]);
			}
		}

		for (int i = 0; i < v1.size(); ++i)
		{
			int j = find(set3,v1[i]);
			if (j != -1)
			{
				Vertex3d v;
				v.x = v1[i].x;
				v.y = v1[i].y;
				v.z = set3[j].z;
				v.name = v1.name;
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
					Edge3d e = Edge3d(s1,s2);
					Edge2d e_xy = project_e(e, x_y);
					int index_xy = find_edge(obj1.edges, e_xy);
					Edge2d e_yz = project_e(e, y_z);
					int index_yz = find_edge(obj2.edges, e_yz);
					Edge2d e_xz = project_e(e, x_z);
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
		for (int i = 0; i < set.size(); ++i)
		{
			string s1 = set[i].name; 
			if (s1.compare(s.name))
				return i;

		}
		return -1;
	}

	int find_edge(vector<Edge2d> set, Edge2d s)
	{
		for (int i = 0; i < set.size(); ++i)
		{
			string s1 = set[i].name; 
			if ((s1.compare(s.name)) && (set[i].v1 = s.v1) && (set[i].v2 = s.v2))  
				return i;

		}
		return -1;
	}

	
}