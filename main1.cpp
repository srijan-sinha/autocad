#include "myarea.h"
#include <gtkmm/application.h>
#include <gtkmm/window.h>
#include "file_handle.h"
int main(int argc, char** argv)
{
   auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

	Gtk::Window win;
    win.set_title("ProCad");
   	file_handle f = file_handle("input_3d_3.txt");
	object3d project = f.input3d();
	
	projection p;
	p.solid = project;
	vector<double> x_y;
	vector<double> y_z;
	vector<double> x_z;

	x_y.push_back(10);
	x_y.push_back(10);
	x_y.push_back(10);

	y_z.push_back(-8);
	y_z.push_back(5);
	y_z.push_back(15);
	
	x_z.push_back(0);
	x_z.push_back(1);
	x_z.push_back(0);
	p.direction = x_y;
	
	p.project();
	object2d proje = p.proj;
	cout<<"Final output"<<endl;
	
	cout<<"Final number of vertices "<<proje.vertices.size()<<endl;
	for (int i = 0; i < proje.vertices.size(); ++i)
	{
		// cout<<"Vertex "<<i<<" "<<proje.vertices[i].x<<" "<<proje.vertices[i].y<<" "<<proje.vertices[i].z<<endl;

	}
	cout<<"Final number of edges "<<proje.edges.size()<<endl;
	for (int i = 0; i < proje.edges.size(); ++i)
	{
		// cout<<"Edge "<<i<<" Vertex 1 "<<proje.edges[i].v1.x<<" "<<proje.edges[i].v1.y<<" "<<proje.edges[i].v1.z<<endl;
		// cout<<"Edge "<<i<<" Vertex 2 "<<proje.edges[i].v2.x<<" "<<proje.edges[i].v2.y<<" "<<proje.edges[i].v2.z<<"    "<<proje.edges[i].hidden<<endl<<endl;
	}	
	MyArea area;
	area.obj = proje;
	win.add(area);
	area.show();
		
   return app->run(win);
}