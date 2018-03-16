#include "elements3d.h"
#include "elements2d.h"
#include "2dto3d.h"
//#include "3dto2d.h"
#include<iostream>
using namespace std;
int main()
{
	
	Vertex2d v1 = Vertex2d(0,0,0,"A");
	cout<<"Vertex2d ";
	for (int i = 0; i < v1.name.size(); ++i)
	{
		cout<<v1.name[i];
	}
	cout<<" x: "<<v1.x<<" y: "<<v1.y<<" z: "<<v1.z<<endl;

	Vertex2d vr1 = Vertex2d(0,0,0,"D");
	cout<<"Vertex2d ";
	for (int i = 0; i < vr1.name.size(); ++i)
	{
		cout<<vr1.name[i];
	}
	cout<<" x: "<<vr1.x<<" y: "<<vr1.y<<" z: "<<vr1.z<<endl;
//----------------------------------------
	Vertex2d v2 = Vertex2d(1,0,0,"B");
	cout<<"Vertex2d ";
	for (int i = 0; i < v2.name.size(); ++i)
	{
		cout<<v2.name[i];
	}
	cout<<" x: "<<v2.x<<" y: "<<v2.y<<" z: "<<v2.z<<endl;

	Vertex2d vr2 = Vertex2d(1,0,0,"C");
	cout<<"Vertex2d ";
	for (int i = 0; i < vr2.name.size(); ++i)
	{
		cout<<vr2.name[i];
	}
	cout<<" x: "<<vr2.x<<" y: "<<vr2.y<<" z: "<<vr2.z<<endl;

//-------------------------------------
	Vertex2d v3 = Vertex2d(0,1,0,"EH");
	cout<<"Vertex2d ";
	for (int i = 0; i < v3.name.size(); ++i)
	{
		cout<<v3.name[i];
	}
	cout<<" x: "<<v3.x<<" y: "<<v3.y<<" z: "<<v3.z<<endl;
	
	Vertex2d vr3 = Vertex2d(0,1,0,"EH");
	cout<<"Vertex2d ";
	for (int i = 0; i < vr3.name.size(); ++i)
	{
		cout<<vr3.name[i];
	}
	cout<<" x: "<<vr3.x<<" y: "<<vr3.y<<" z: "<<vr3.z<<endl;

//-----------------------------------------
	
	Vertex2d v4 = Vertex2d(1,1,0,"FG");
	cout<<"Vertex2d ";
	for (int i = 0; i < v4.name.size(); ++i)
	{
		cout<<v4.name[i];
	}
	cout<<" x: "<<v4.x<<" y: "<<v4.y<<" z: "<<v4.z<<endl;
	
	Vertex2d vr4 = Vertex2d(1,1,0,"FG");
	cout<<"Vertex2d ";
	for (int i = 0; i < vr4.name.size(); ++i)
	{
		cout<<vr4.name[i];
	}
	cout<<" x: "<<vr4.x<<" y: "<<vr4.y<<" z: "<<vr4.z<<endl;
//-----------------------------------------
	
	Edge2d e1 = Edge2d(v1,v2);
	Edge2d e2 = Edge2d(v2,v4);
	Edge2d e3 = Edge2d(v3,v4);
	Edge2d e4 = Edge2d(v1,v3);
	Edge2d er1 = Edge2d(vr1,vr2);
	Edge2d er2 = Edge2d(vr2,vr4);
	Edge2d er3 = Edge2d(vr3,vr4);
	Edge2d er4 = Edge2d(vr1,vr3);
	
	object2d obj1;
	vector<Vertex2d> v;
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);
	v.push_back(vr1);
	v.push_back(vr2);
	v.push_back(vr3);
	v.push_back(vr4);
	
	vector<Edge2d> e;
	e.push_back(e1);
	e.push_back(e2);
	e.push_back(e3);
	e.push_back(e4);
	e.push_back(er1);
	e.push_back(er2);
	e.push_back(er3);
	e.push_back(er4);
	
	obj1.vertices = v;
	obj1.edges = e;




	Vertex2d ve1 = Vertex2d(0,0,0,"A");
	cout<<"Vertex2d ";
	for (int i = 0; i < ve1.name.size(); ++i)
	{
		cout<<ve1.name[i];
	}
	cout<<" x: "<<ve1.x<<" y: "<<ve1.y<<" z: "<<ve1.z<<endl;

	Vertex2d ver1 = Vertex2d(0,0,0,"B");
	cout<<"Vertex2d ";
	for (int i = 0; i < ver1.name.size(); ++i)
	{
		cout<<ver1.name[i];
	}
	cout<<" x: "<<ver1.x<<" y: "<<ver1.y<<" z: "<<ver1.z<<endl;
//-------------------------------------
	Vertex2d ve2 = Vertex2d(0,0,1,"D");
	cout<<"Vertex2d ";
	for (int i = 0; i < ve2.name.size(); ++i)
	{
		cout<<ve2.name[i];
	}
	cout<<" x: "<<ve2.x<<" y: "<<ve2.y<<" z: "<<ve2.z<<endl;

	Vertex2d ver2 = Vertex2d(0,0,1,"C");
	cout<<"Vertex2d ";
	for (int i = 0; i < ver2.name.size(); ++i)
	{
		cout<<ver2.name[i];
	}
	cout<<" x: "<<ver2.x<<" y: "<<ver2.y<<" z: "<<ver2.z<<endl;
//-------------------------------------

	Vertex2d ve3 = Vertex2d(0,1,0,"E");
	cout<<"Vertex2d ";
	for (int i = 0; i < ve3.name.size(); ++i)
	{
		cout<<ve3.name[i];
	}
	cout<<" x: "<<ve3.x<<" y: "<<ve3.y<<" z: "<<ve3.z<<endl;

	Vertex2d ver3 = Vertex2d(0,1,0,"F");
	cout<<"Vertex2d ";
	for (int i = 0; i < ver3.name.size(); ++i)
	{
		cout<<ver3.name[i];
	}
	cout<<" x: "<<ver3.x<<" y: "<<ver3.y<<" z: "<<ver3.z<<endl;
//--------------------------------------
	Vertex2d ve4 = Vertex2d(0,1,1,"H");
	cout<<"Vertex2d ";
	for (int i = 0; i < ve4.name.size(); ++i)
	{
		cout<<ve4.name[i];
	}
	cout<<" x: "<<ve4.x<<" y: "<<ve4.y<<" z: "<<ve4.z<<endl;
	

	Vertex2d ver4 = Vertex2d(0,1,1,"G");
	cout<<"Vertex2d ";
	for (int i = 0; i < ver4.name.size(); ++i)
	{
		cout<<ver4.name[i];
	}
	cout<<" x: "<<ver4.x<<" y: "<<ver4.y<<" z: "<<ver4.z<<endl;
//-------------------------------------------
	Edge2d ee1 = Edge2d(ve1,ve2);
	Edge2d ee2 = Edge2d(ve2,ve4);
	Edge2d ee3 = Edge2d(ve3,ve4);
	Edge2d ee4 = Edge2d(ve1,ve3);
	Edge2d eer1 = Edge2d(ver1,ver2);
	Edge2d eer2 = Edge2d(ver2,ver4);
	Edge2d eer3 = Edge2d(ver3,ver4);
	Edge2d eer4 = Edge2d(ver1,ver3);
	
	object2d obj2;
	vector<Vertex2d> ve;
	ve.push_back(ve1);
	ve.push_back(ve2);
	ve.push_back(ve3);
	ve.push_back(ve4);
	ve.push_back(ver1);
	ve.push_back(ver2);
	ve.push_back(ver3);
	ve.push_back(ver4);
	
	vector<Edge2d> ee;
	ee.push_back(ee1);
	ee.push_back(ee2);
	ee.push_back(ee3);
	ee.push_back(ee4);
	ee.push_back(eer1);
	ee.push_back(eer2);
	ee.push_back(eer3);
	ee.push_back(eer4);
	
	obj2.vertices = ve;
	obj2.edges = ee;





	Vertex2d vee1 = Vertex2d(0,0,0,"EA");
	cout<<"Vertex2d ";
	for (int i = 0; i < vee1.name.size(); ++i)
	{
		cout<<vee1.name[i];
	}
	cout<<" x: "<<vee1.x<<" y: "<<vee1.y<<" z: "<<vee1.z<<endl;

	Vertex2d vee1 = Vertex2d(0,0,0,"EA");
	cout<<"Vertex2d ";
	for (int i = 0; i < vee1.name.size(); ++i)
	{
		cout<<vee1.name[i];
	}
	cout<<" x: "<<vee1.x<<" y: "<<vee1.y<<" z: "<<vee1.z<<endl;
//---------------------------------------

	Vertex2d vee2 = Vertex2d(1,0,0,"FB");
	cout<<"Vertex2d ";
	for (int i = 0; i < vee2.name.size(); ++i)
	{
		cout<<vee2.name[i];
	}
	cout<<" x: "<<vee2.x<<" y: "<<vee2.y<<" z: "<<vee2.z<<endl;

	Vertex2d vee2 = Vertex2d(1,0,0,"FB");
	cout<<"Vertex2d ";
	for (int i = 0; i < vee2.name.size(); ++i)
	{
		cout<<vee2.name[i];
	}
	cout<<" x: "<<vee2.x<<" y: "<<vee2.y<<" z: "<<vee2.z<<endl;
//-------------------------------------

	Vertex2d vee3 = Vertex2d(0,0,1,"HD");
	cout<<"Vertex2d ";
	for (int i = 0; i < vee3.name.size(); ++i)
	{
		cout<<vee3.name[i];
	}
	cout<<" x: "<<vee3.x<<" y: "<<vee3.y<<" z: "<<vee3.z<<endl;

	Vertex2d vee3 = Vertex2d(0,0,1,"HD");
	cout<<"Vertex2d ";
	for (int i = 0; i < vee3.name.size(); ++i)
	{
		cout<<vee3.name[i];
	}
	cout<<" x: "<<vee3.x<<" y: "<<vee3.y<<" z: "<<vee3.z<<endl;
//---------------------------------------
	Vertex2d vee4 = Vertex2d(1,0,1,"GC");
	cout<<"Vertex2d ";
	for (int i = 0; i < vee4.name.size(); ++i)
	{
		cout<<vee4.name[i];
	}
	cout<<" x: "<<vee4.x<<" y: "<<vee4.y<<" z: "<<vee4.z<<endl;
	
	Vertex2d vee4 = Vertex2d(1,0,1,"GC");
	cout<<"Vertex2d ";
	for (int i = 0; i < vee4.name.size(); ++i)
	{
		cout<<vee4.name[i];
	}
	cout<<" x: "<<vee4.x<<" y: "<<vee4.y<<" z: "<<vee4.z<<endl;
//-------------------------------------------	
	Edge2d eee1 = Edge2d(vee1,vee2);
	Edge2d eee2 = Edge2d(vee2,vee4);
	Edge2d eee3 = Edge2d(vee3,vee4);
	Edge2d eee4 = Edge2d(vee1,vee3);
	Edge2d eee1 = Edge2d(vee1,vee2);
	Edge2d eee2 = Edge2d(vee2,vee4);
	Edge2d eee3 = Edge2d(vee3,vee4);
	Edge2d eee4 = Edge2d(vee1,vee3);
	
	object2d obj3;
	vector<Vertex2d> vee;
	vee.push_back(vee1);
	vee.push_back(vee2);
	vee.push_back(vee3);
	vee.push_back(vee4);
	vee.push_back(vee1);
	vee.push_back(vee2);
	vee.push_back(vee3);
	vee.push_back(vee4);
	
	vector<Edge2d> eee;
	eee.push_back(eee1);
	eee.push_back(eee2);
	eee.push_back(eee3);
	eee.push_back(eee4);
	
	eee.push_back(eee1);
	eee.push_back(eee2);
	eee.push_back(eee3);
	eee.push_back(eee4);
	
	obj3.vertices = vee;
	obj3.edges = eee;
	rev_3dto2d r;
	vector<Vertex3d> vi = r.cor_vertex(obj1,obj2,obj3);
	for (int i = 0; i < vi.size(); ++i)
	{
		cout<<vi[i].x<<","<<vi[i].y<<","<<vi[i].z<<endl;
	}
	return 0;
}
