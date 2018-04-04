//file input -> return 3d/2d object

//final object input -> return file with vertices, edges and labels
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

class file_handle
{
	public:
	string filename;
	file_handle(string filename_c)
	{
		filename = filename_c;
	}

	object2d input2d() 
	{
	    
	    ifstream inFile;
	    
	    inFile.open(filename);
	    if (!inFile) 
	        cout << "Unable to open file";
	    string dim;
	    inFile>>dim;
	    string vertices;
	    inFile>>vertices;
	    int num_vert;
	    inFile>>num_vert;
	    vector<Vertex2d> vert;
	    for (int i = 0; i < num_vert; ++i)
	    {
	        int x,y,z;
	        char a;
	        string label;
	        inFile>>x;
	        inFile>>a;
	        inFile>>y;
	        inFile>>a;
	        inFile>>z;
	        inFile>>label;
	        Vertex2d v = Vertex2d(x,y,z,label);
	        vert.push_back(v);
	    }

	    string Edges;
	    inFile>>Edges;
	    int num_edges;
	    inFile>>num_edges;
	    vector<Edge2d> edge;

	    for (int i = 0; i < num_edges; ++i)
	    {
	        Edge2d e1;
	        char label1;
	        char label2;
	        
	        inFile>>label1;
	        inFile>>label2;
	        string l1(1, label1);
	        string l2(1, label2);

	        for (int i = 0; i < vert.size(); ++i)
	        {
	            if (vert[i].name.compare(l1)==0)
	            {
	                e1.v1 = vert[i];
	                
	            }
	            if (vert[i].name.compare(l2)==0)
	            {
	                e1.v2 = vert[i];
	            }
	        }

	        e1.name = e1.v1.name + e1.v2.name;
	        edge.push_back(e1);
	    }

	    object2d obj;
	    obj.vertices = vert;
	    obj.edges = edge;
	    inFile.close();
	    return obj;
	}

	object3d input3d() 
	{
	    
	    ifstream inFile;
	    
	    inFile.open(filename);
	    if (!inFile) 
	        cout << "Unable to open file";
	    string dim;
	    inFile>>dim;
	    string vertices;
	    inFile>>vertices;
	    int num_vert;
	    inFile>>num_vert;
	    vector<Vertex3d> vert;
	    for (int i = 0; i < num_vert; ++i)
	    {
	        int x,y,z;
	        char a;
	        string label;
	        inFile>>x;
	        inFile>>a;
	        inFile>>y;
	        inFile>>a;
	        inFile>>z;
	        inFile>>label;
	        Vertex3d v = Vertex3d(x,y,z,label);
	        vert.push_back(v);
	    }

	    string Edges;
	    inFile>>Edges;
	    // cout<<Edges;
	    int num_edges;
	    inFile>>num_edges;
	    // cout<<num_edges<<endl;
	    vector<Edge3d> edge;

	    for (int i = 0; i < num_edges; ++i)
	    {
	        Edge3d e1;
	        char label1;
	        char label2;
	        
	        inFile>>label1;
	        inFile>>label2;
	        string l1(1, label1);
	        string l2(1, label2);
	        for (int i = 0; i < vert.size(); ++i)
	        {
	            if (vert[i].name.compare(l1)==0)
	                e1.v1 = vert[i];
	            if (vert[i].name.compare(l2)==0)
	                e1.v2 = vert[i];
	        }
	        e1.name = e1.v1.name + e1.v2.name;
	        edge.push_back(e1);
	    }

	    string Surfaces;
	    inFile>>Surfaces;
	    int num_surf;
	    inFile>>num_surf;
	    vector<Surface3d> surf;

	    for (int i = 0; i < num_surf; ++i)
	    {
	    	int num;
	    	inFile>>num;
	    	vector<Edge3d> v;
	        for (int j = 0; j < num; ++j)
            {
            	
            	string label;
            	inFile>>label;
            	for (int k = 0; k < num_edges; ++k)
            	{
            		if (edge[k].name.compare(label)==0)
            			v.push_back(edge[k]);
            	}
            }
            Surface3d s =Surface3d(v,v.size());
            surf.push_back(s);
        }

	    object3d obj;
	    obj.vertices = vert;
	    obj.edges = edge;
	    obj.surfaces = surf;
	    inFile.close();

	    return obj;
	}
};