#include "myarea.h"
#include <gtkmm/application.h>
#include <gtkmm/window.h>
#include "file_handle.h"
int main(int argc, char** argv)
{
   auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

	Gtk::Window win;
    win.set_title("ProCad");
   	file_handle f = file_handle("input_3d.txt");
	object3d project = f.input3d();
	projection p;
	p.solid = project;
	vector<double> x_y;
	vector<double> y_z;
	vector<double> x_z;

	x_y.push_back(5);
	x_y.push_back(15);
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
	MyArea area;
	area.obj = proje;
	win.add(area);
	area.show();
		
   return app->run(win);
}