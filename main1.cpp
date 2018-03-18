#include "myarea.h"
#include <gtkmm/application.h>
#include <gtkmm/window.h>
int main(int argc, char** argv)
{
   auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

   Gtk::Window win;
   win.set_title("ProCad");

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
	w2.push_back(e3_2);
	vector<Edge3d> w3;
	w3.push_back(e3_6);
	w3.push_back(e3_7);
	w3.push_back(e3_3);
	vector<Edge3d> w4;
	w4.push_back(e3_7);
	w4.push_back(e3_8);
	w4.push_back(e3_4);
	vector<Edge3d> w5;
	w5.push_back(e3_8);
	w5.push_back(e3_5);
	w5.push_back(e3_1);
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

	x_y.push_back(10);
	x_y.push_back(12);
	x_y.push_back(-10);

	y_z.push_back(1);
	y_z.push_back(0);
	y_z.push_back(0);
	
	x_z.push_back(0);
	x_z.push_back(1);
	x_z.push_back(0);
	p.direction = x_y;
	
	p.project();

	
	object2d proje = p.proj;
	/*cout<<proje.vertices.size()<<endl;
	for (int i = 0; i < proje.vertices.size(); ++i)
	{
		cout<<proje.vertices[i].x<<" "<<proje.vertices[i].y<<" "<<proje.vertices[i].z<<endl;

	}
	cout<<"finally"<<endl;
	cout<<proje.edges.size()<<endl;
	for (int i = 0; i < proje.edges.size(); ++i)
	{
		cout<<proje.edges[i].v1.x<<" "<<proje.edges[i].v1.y<<" "<<proje.edges[i].v1.z<<"    ";
		cout<<proje.edges[i].v2.x<<" "<<proje.edges[i].v2.y<<" "<<proje.edges[i].v2.z<<"    "<<proje.edges[i].hidden<<endl;
	}*/
	
		x_y.push_back(10);
		x_y.push_back(12);
		x_y.push_back(-10);

		y_z.push_back(1);
		y_z.push_back(0);
		y_z.push_back(0);
		
		x_z.push_back(0);
		x_z.push_back(1);
		x_z.push_back(0);
		p.direction = x_y;
		p.project();

	
		proje = p.proj;
		MyArea area;
		area.obj = proje;
		win.add(area);
		area.show();
		
   return app->run(win);
}