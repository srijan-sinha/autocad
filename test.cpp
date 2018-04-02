#include <iostream>
#include <iomanip>
#include <fstream>
#include "backend_header.h"
using namespace std;

object2d input2d() 
{
    
    ifstream inFile;
    
    inFile.open("input.txt");
    if (!inFile) 
        cout << "Unable to open file";
    string dim;
    inFile>>dim;
    cout<<dim<<endl;
    string vertices;
    inFile>>vertices;
    cout<<vertices<<endl;
    int num_vert;
    inFile>>num_vert;
    cout<<num_vert<<endl;
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
        cout<<"x="<<v.x<<" y="<<v.y<<" z="<<v.z<<" name="<<v.name<<endl;
        vert.push_back(v);
    }
    for (int i = 0; i < vert.size(); ++i)
    {
        cout<<vert[i].x<<" "<<vert[i].y<<" "<<vert[i].z<<" "<<vert[i].name<<endl;
    }
    string Edges;
    inFile>>Edges;
    cout<<Edges;
    int num_edges;
    inFile>>num_edges;
    cout<<num_edges<<endl;
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
        cout<<e1.v1.name<<e1.v2.name<<endl;
        e1.name = e1.v1.name + e1.v2.name;
        edge.push_back(e1);
        //Vertex2d v = Vertex2d(x,y,z,label);
        //cout<<"x="<<v.x<<" y="<<v.y<<" z="<<v.z<<" name="<<v.name<<endl;
        //vert.push_back(v);
    }
    for (int i = 0; i < edge.size(); ++i)
    {
        cout<<edge[i].v1.x<<" "<<edge[i].v1.y<<" "<<edge[i].v1.z<<"    ";
        cout<<edge[i].v2.x<<" "<<edge[i].v2.y<<" "<<edge[i].v2.z<<" "<<edge[i].name<<endl;
           
    }
    object2d obj;
    obj.vertices = vert;
    obj.edges = edge;
    inFile.close();
    return obj;
}