//file input -> return 3d/2d object

//final object input -> return file with vertices, edges and labels
#include <iostream>
#include <iomanip>
#include <fstream>
//#include "backend_header.h"
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
	    // cout<<"before processing"<<endl;
	    string dim;
	    inFile>>dim;
	    // cout<<dim<<endl;
	    string vertices;
	    inFile>>vertices;
	    // cout<<vertices<<endl;
	    int num_vert;
	    inFile>>num_vert;
	    // cout<<num_vert<<endl;
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
	        //cout<<"x="<<v.x<<" y="<<v.y<<" z="<<v.z<<" name="<<v.name<<endl;
	        vert.push_back(v);
	    }
	    for (int i = 0; i < vert.size(); ++i)
	    {
	        cout<<vert[i].x<<" "<<vert[i].y<<" "<<vert[i].z<<" "<<vert[i].name<<endl;
	    }
	    string Edges;
	    inFile>>Edges;
	    // cout<<Edges;
	    int num_edges;
	    inFile>>num_edges;
	    // cout<<num_edges<<endl;
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
	        //cout<<label1<<label2<<endl;
	        for (int i = 0; i < vert.size(); ++i)
	        {
	            //cout<<endl;
	            if (vert[i].name.compare(l1)==0)
	            {
	                e1.v1 = vert[i];
	                
	            }
	            if (vert[i].name.compare(l2)==0)
	            {
	                e1.v2 = vert[i];
	            }
	        }
	        // cout<<e1.v1.name<<e1.v2.name<<endl;
	        e1.name = e1.v1.name + e1.v2.name;
	        edge.push_back(e1);
	        //Vertex2d v = Vertex2d(x,y,z,label);
	        //cout<<"x="<<v.x<<" y="<<v.y<<" z="<<v.z<<" name="<<v.name<<endl;
	        //vert.push_back(v);
	    }
	    for (int i = 0; i < edge.size(); ++i)
	    {
	        // cout<<edge[i].v1.x<<" "<<edge[i].v1.y<<" "<<edge[i].v1.z<<"    ";
	        // cout<<edge[i].v2.x<<" "<<edge[i].v2.y<<" "<<edge[i].v2.z<<" "<<edge[i].name<<endl;
	           
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
	    // cout<<"before processing"<<endl;
	    string dim;
	    inFile>>dim;
	    // cout<<dim<<endl;
	    string vertices;
	    inFile>>vertices;
	    // cout<<vertices<<endl;
	    int num_vert;
	    inFile>>num_vert;
	    // cout<<num_vert<<endl;
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
	        //cout<<"x="<<v.x<<" y="<<v.y<<" z="<<v.z<<" name="<<v.name<<endl;
	        vert.push_back(v);
	    }
	    for (int i = 0; i < vert.size(); ++i)
	    {
	        // cout<<vert[i].x<<" "<<vert[i].y<<" "<<vert[i].z<<" "<<vert[i].name<<endl;
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
	        //cout<<label1<<label2<<endl;
	        for (int i = 0; i < vert.size(); ++i)
	        {
	            //cout<<endl;
	            if (vert[i].name.compare(l1)==0)
	            {
	                e1.v1 = vert[i];
	                
	            }
	            if (vert[i].name.compare(l2)==0)
	            {
	                e1.v2 = vert[i];
	            }
	        }
	        cout<<e1.v1.name<<e1.v2.name<<endl;
	        e1.name = e1.v1.name + e1.v2.name;
	        edge.push_back(e1);
	        //Vertex2d v = Vertex2d(x,y,z,label);
	        //cout<<"x="<<v.x<<" y="<<v.y<<" z="<<v.z<<" name="<<v.name<<endl;
	        //vert.push_back(v);
	    }
	    for (int i = 0; i < edge.size(); ++i)
	    {
	        // cout<<edge[i].v1.x<<" "<<edge[i].v1.y<<" "<<edge[i].v1.z<<"    ";
	        // cout<<edge[i].v2.x<<" "<<edge[i].v2.y<<" "<<edge[i].v2.z<<" "<<edge[i].name<<endl;
	           
	    }

	    string Surfaces;
	    inFile>>Surfaces;
	    // cout<<Surfaces;
	    int num_surf;
	    inFile>>num_surf;
	    // cout<<num_surf<<endl;
	    vector<Surface3d> surf;

	    for (int i = 0; i < num_surf; ++i)
	    {
	    	int num;
	    	inFile>>num;
	    	cout<<"num ("<<i<<"): "<<num<<endl;
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
        for (int i = 0; i < surf.size(); ++i)
        {
        	cout<<"next surface"<<endl;
        	for (int j = 0; j < surf[i].edges.size(); ++j)
        	{
        		// cout<<surf[i].edges[j].v1.x<<" "<<surf[i].edges[j].v1.y<<" "<<surf[i].edges[j].v1.z<<"   ";
				// cout<<surf[i].edges[j].v2.x<<" "<<surf[i].edges[j].v2.y<<" "<<surf[i].edges[j].v2.z<<"   "<<surf[i].edges[j].name<<endl;
	
        	}
        }
	    object3d obj;
	    obj.vertices = vert;
	    obj.edges = edge;
	    obj.surfaces = surf;
	    inFile.close();
	    cout<<"********************************file_handle.h exit"<<endl;
	    return obj;
	}
};