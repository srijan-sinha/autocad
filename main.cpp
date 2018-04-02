#include "backend_header.h"
#include<iostream>
using namespace std;
int main()
{
	cout<<"*******************************testing 2dto3d vertex forming"<<endl;
	
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
	Vertex2d v3 = Vertex2d(0,1,0,"H");
	cout<<"Vertex2d ";
	for (int i = 0; i < v3.name.size(); ++i)
	{
		cout<<v3.name[i];
	}
	cout<<" x: "<<v3.x<<" y: "<<v3.y<<" z: "<<v3.z<<endl;
	
	Vertex2d vr3 = Vertex2d(0,1,0,"E");
	cout<<"Vertex2d ";
	for (int i = 0; i < vr3.name.size(); ++i)
	{
		cout<<vr3.name[i];
	}
	cout<<" x: "<<vr3.x<<" y: "<<vr3.y<<" z: "<<vr3.z<<endl;

//-----------------------------------------
	
	Vertex2d v4 = Vertex2d(1,1,0,"F");
	cout<<"Vertex2d ";
	for (int i = 0; i < v4.name.size(); ++i)
	{
		cout<<v4.name[i];
	}
	cout<<" x: "<<v4.x<<" y: "<<v4.y<<" z: "<<v4.z<<endl;
	
	Vertex2d vr4 = Vertex2d(1,1,0,"G");
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





	Vertex2d vee1 = Vertex2d(0,0,0,"A");
	cout<<"Vertex2d ";
	for (int i = 0; i < vee1.name.size(); ++i)
	{
		cout<<vee1.name[i];
	}
	cout<<" x: "<<vee1.x<<" y: "<<vee1.y<<" z: "<<vee1.z<<endl;

	Vertex2d veer1 = Vertex2d(0,0,0,"E");
	cout<<"Vertex2d ";
	for (int i = 0; i < veer1.name.size(); ++i)
	{
		cout<<veer1.name[i];
	}
	cout<<" x: "<<veer1.x<<" y: "<<veer1.y<<" z: "<<veer1.z<<endl;
//---------------------------------------

	Vertex2d vee2 = Vertex2d(1,0,0,"F");
	cout<<"Vertex2d ";
	for (int i = 0; i < vee2.name.size(); ++i)
	{
		cout<<vee2.name[i];
	}
	cout<<" x: "<<vee2.x<<" y: "<<vee2.y<<" z: "<<vee2.z<<endl;

	Vertex2d veer2 = Vertex2d(1,0,0,"B");
	cout<<"Vertex2d ";
	for (int i = 0; i < veer2.name.size(); ++i)
	{
		cout<<veer2.name[i];
	}
	cout<<" x: "<<veer2.x<<" y: "<<veer2.y<<" z: "<<veer2.z<<endl;
//-------------------------------------

	Vertex2d vee3 = Vertex2d(0,0,1,"D");
	cout<<"Vertex2d ";
	for (int i = 0; i < vee3.name.size(); ++i)
	{
		cout<<vee3.name[i];
	}
	cout<<" x: "<<vee3.x<<" y: "<<vee3.y<<" z: "<<vee3.z<<endl;

	Vertex2d veer3 = Vertex2d(0,0,1,"H");
	cout<<"Vertex2d ";
	for (int i = 0; i < veer3.name.size(); ++i)
	{
		cout<<veer3.name[i];
	}
	cout<<" x: "<<veer3.x<<" y: "<<veer3.y<<" z: "<<veer3.z<<endl;
//---------------------------------------
	Vertex2d vee4 = Vertex2d(1,0,1,"G");
	cout<<"Vertex2d ";
	for (int i = 0; i < vee4.name.size(); ++i)
	{
		cout<<vee4.name[i];
	}
	cout<<" x: "<<vee4.x<<" y: "<<vee4.y<<" z: "<<vee4.z<<endl;
	
	Vertex2d veer4 = Vertex2d(1,0,1,"C");
	cout<<"Vertex2d ";
	for (int i = 0; i < veer4.name.size(); ++i)
	{
		cout<<vee4.name[i];
	}
	cout<<" x: "<<veer4.x<<" y: "<<veer4.y<<" z: "<<veer4.z<<endl;
//-------------------------------------------	
	Edge2d eee1 = Edge2d(vee1,vee2);
	Edge2d eee2 = Edge2d(vee2,vee4);
	Edge2d eee3 = Edge2d(vee3,vee4);
	Edge2d eee4 = Edge2d(vee1,vee3);
	Edge2d eeer1 = Edge2d(veer1,veer2);
	Edge2d eeer2 = Edge2d(veer2,veer4);
	Edge2d eeer3 = Edge2d(veer3,veer4);
	Edge2d eeer4 = Edge2d(veer1,veer3);
	
	object2d obj3;
	vector<Vertex2d> vee;
	vee.push_back(vee1);
	vee.push_back(vee2);
	vee.push_back(vee3);
	vee.push_back(vee4);
	vee.push_back(veer1);
	vee.push_back(veer2);
	vee.push_back(veer3);
	vee.push_back(veer4);
	
	vector<Edge2d> eee;
	eee.push_back(eee1);
	eee.push_back(eee2);
	eee.push_back(eee3);
	eee.push_back(eee4);
	
	eee.push_back(eeer1);
	eee.push_back(eeer2);
	eee.push_back(eeer3);
	eee.push_back(eeer4);
	
	obj3.vertices = vee;
	obj3.edges = eee;
	rev_3dto2d r;
	/*vector<Vertex3d> vi = r.cor_vertex(obj1,obj2,obj3);
	for (int i = 0; i < vi.size(); ++i)
	{
		cout<<vi[i].x<<","<<vi[i].y<<","<<vi[i].z<<endl;
	}
*/
	cout<<"*******************************testing 3dto2d projection"<<endl;
	Vertex3d v3_1 = Vertex3d(0,0,0,"A");
	Vertex3d v3_2 = Vertex3d(2,0,0,"B");
	Vertex3d v3_3 = Vertex3d(2,2,0,"C");
	Vertex3d v3_4 = Vertex3d(0,2,0,"D");
	Vertex3d v3_5 = Vertex3d(1,1,2,"E");
	Edge3d e3_1 = Edge3d(v3_1,v3_2);
	Edge3d e3_2 = Edge3d(v3_2,v3_3);
	Edge3d e3_3 = Edge3d(v3_3,v3_4);
	Edge3d e3_4 = Edge3d(v3_4,v3_1);
	Edge3d e3_5 = Edge3d(v3_1,v3_5);
	Edge3d e3_6 = Edge3d(v3_2,v3_5);
	Edge3d e3_7 = Edge3d(v3_3,v3_5);
	Edge3d e3_8 = Edge3d(v3_4,v3_5);
	vector<Edge3d> w1;
	w1.push_back(e3_1);
	w1.push_back(e3_2);
	w1.push_back(e3_3);
	w1.push_back(e3_4);
	vector<Edge3d> w2;
	w2.push_back(e3_5);
	w2.push_back(e3_6);
	w2.push_back(e3_1);
	vector<Edge3d> w3;
	w3.push_back(e3_6);
	w3.push_back(e3_7);
	w3.push_back(e3_2);
	vector<Edge3d> w4;
	w4.push_back(e3_7);
	w4.push_back(e3_8);
	w4.push_back(e3_3);
	vector<Edge3d> w5;
	w5.push_back(e3_8);
	w5.push_back(e3_5);
	w5.push_back(e3_4);
	Surface3d s3_1 = Surface3d(w1,w1.size());
	Surface3d s3_2 = Surface3d(w2,w2.size());
	Surface3d s3_3 = Surface3d(w3,w3.size());
	Surface3d s3_4 = Surface3d(w4,w4.size());
	Surface3d s3_5 = Surface3d(w5,w5.size());
	projection p;
	p.solid.vertices.push_back(v3_1);
	p.solid.vertices.push_back(v3_2);
	p.solid.vertices.push_back(v3_3);
	p.solid.vertices.push_back(v3_4);
	p.solid.vertices.push_back(v3_5);
	p.solid.edges.push_back(e3_1);
	p.solid.edges.push_back(e3_2);
	p.solid.edges.push_back(e3_3);
	p.solid.edges.push_back(e3_4);
	p.solid.edges.push_back(e3_5);
	p.solid.edges.push_back(e3_6);
	p.solid.edges.push_back(e3_7);
	p.solid.edges.push_back(e3_8);
	p.solid.surfaces.push_back(s3_1);
	p.solid.surfaces.push_back(s3_2);
	p.solid.surfaces.push_back(s3_3);
	p.solid.surfaces.push_back(s3_4);
	p.solid.surfaces.push_back(s3_5);
	cout<<"edges in solid 1:"<<endl;
	for (int i = 0; i < p.solid.edges.size(); ++i)
	{
		cout<<p.solid.edges[i].v1.x<<" "<<p.solid.edges[i].v1.y<<" "<<p.solid.edges[i].v1.z<<"    ";
		cout<<p.solid.edges[i].v2.x<<" "<<p.solid.edges[i].v2.y<<" "<<p.solid.edges[i].v2.z<<endl;
	}
	cout<<"$$$$$";


	vector<double> x_y;
	vector<double> y_z;
	vector<double> x_z;

	x_y.push_back(0);
	x_y.push_back(0);
	x_y.push_back(15);

	y_z.push_back(-1);
	y_z.push_back(0)
;	y_z.push_back(0);
	
	x_z.push_back(0);
	x_z.push_back(1);
	x_z.push_back(0);
	p.direction = x_y;
	
	p.project();

	
	object2d proje = p.proj;
	cout<<"finally"<<endl;
	
	cout<<proje.vertices.size()<<endl;
	for (int i = 0; i < proje.vertices.size(); ++i)
	{
		cout<<proje.vertices[i].x<<" "<<proje.vertices[i].y<<" "<<proje.vertices[i].z<<endl;

	}
	cout<<proje.edges.size()<<endl;
	for (int i = 0; i < proje.edges.size(); ++i)
	{
		cout<<proje.edges[i].v1.x<<" "<<proje.edges[i].v1.y<<" "<<proje.edges[i].v1.z<<"    ";
		cout<<proje.edges[i].v2.x<<" "<<proje.edges[i].v2.y<<" "<<proje.edges[i].v2.z<<"    "<<proje.edges[i].hidden<<endl;
	}
/*
	cout<<"*******************************testing 3dto2d position_fore"<<endl;
	Vertex3d v4_1 = Vertex3d(0,0,0,"A");
	Vertex3d v4_2 = Vertex3d(2,0,0,"B");
	Vertex3d v4_3 = Vertex3d(2,2,0,"C");
	Vertex3d v4_4 = Vertex3d(0,2,0,"D");
	Vertex3d v4_5 = Vertex3d(1,1,1,"E");
	Edge3d e4_1 = Edge3d(v4_1,v4_2);
	Edge3d e4_2 = Edge3d(v4_2,v4_3);
	Edge3d e4_3 = Edge3d(v4_3,v4_4);
	Edge3d e4_4 = Edge3d(v4_4,v4_1);
	vector<Edge3d> w1_1;
	w1_1.push_back(e4_1);
	w1_1.push_back(e4_2);
	w1_1.push_back(e4_3);
	w1_1.push_back(e4_4);
	p.direction = x_y;
	Surface3d s4_1 = Surface3d(w1_1,w1_1.size());
	cout<<p.position_fore(v4_5, s4_1)<<endl;

	cout<<"*******************************testing 3dto2d ray_casting"<<endl;
	Vertex2d v5_1 = Vertex2d(0,0,0,"A");
	Vertex2d v5_2 = Vertex2d(2,0,0,"B");
	Vertex2d v5_3 = Vertex2d(2,2,0,"C");
	Vertex2d v5_4 = Vertex2d(0,2,0,"D");
	Vertex2d v5_5 = Vertex2d(0.5,0.5,0,"E");
	Vertex2d v5_6 = Vertex2d(1.5,1.5,0,"F");
	Edge2d e5_1 = Edge2d(v5_1,v5_2);
	Edge2d e5_2 = Edge2d(v5_2,v5_3);
	Edge2d e5_3 = Edge2d(v5_3,v5_4);
	Edge2d e5_4 = Edge2d(v5_4,v5_1);
	Edge2d e5_5 = Edge2d(v5_5,v5_6);
	vector<Edge2d> r1;
	r1.push_back(e5_1);
	r1.push_back(e5_2);
	r1.push_back(e5_3);
	r1.push_back(e5_4);
	Surface2d s5_1 = Surface2d(r1, r1.size());
	//cout<<endl<<p.inside(e5_5,s5_1);
	cout<<p.ray_casting(v5_5, s5_1);
	*/
	cout<<"************************************testing hidden lines"<<endl;

	return 0;
};
