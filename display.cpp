#include "display.h"
#include <iostream>
#include <cairomm/context.h>

using namespace std;

MainWindow::MainWindow()
: m_button_2d_3d("2D to 3D"),
  m_button_3d_2d("3D to 2D")
{
  set_border_width(30);
  set_size_request(200, 100);
  set_title("AutoCad");

  add(m_box);
  m_box.add(m_grid1);
  m_box.add(m_grid2);
  m_grid1.add(m_button_2d_3d);
  m_grid2.add(m_button_3d_2d);

  m_button_2d_3d.signal_clicked().connect( sigc::mem_fun(*this,
              &MainWindow::on_button_2d_3d) );
  m_button_3d_2d.signal_clicked().connect( sigc::mem_fun(*this,
              &MainWindow::on_button_3d_2d) );

  show_all_children();
}

MainWindow::~MainWindow()
{

}

void MainWindow::on_button_2d_3d()
{
  Input2dWindow* input = new Input2dWindow;
  input->show();
}

void MainWindow::on_button_3d_2d()
{
  Input3dWindow* input = new Input3dWindow;
  input->show();
}

Input2dWindow::Input2dWindow()
: m_button("Create"),
  m_frame1("Input for Creating 3D"),
  m_frame2("3D Wireframe Output"),
  m_box(Gtk::ORIENTATION_VERTICAL)

{
  set_border_width(10);
  set_size_request(1000, 200);
  set_title("Input 2D object file");

  m_file1.set_max_length(50);
  m_file1.set_text("Enter file name for x-y plane");
  m_file1.select_region(0, m_file1.get_text_length());

  m_file2.set_max_length(50);
  m_file2.set_text("Enter file name for y-z plane");
  m_file2.select_region(0, m_file2.get_text_length());

  m_file3.set_max_length(50);
  m_file3.set_text("Enter file name for z-x plane");
  m_file3.select_region(0, m_file3.get_text_length());

  add(m_box);

  m_box.pack_start(m_frame1, Gtk::PACK_SHRINK, 10);
  m_box.pack_start(m_frame2, Gtk::PACK_EXPAND_WIDGET, 10);
  
  m_frame1.add(m_grid);

  m_grid.add(m_file1);
  m_grid.attach_next_to(m_file2, m_file1, Gtk::POS_BOTTOM, 1, 1);
  m_grid.attach_next_to(m_file3, m_file2, Gtk::POS_BOTTOM, 1, 1);
  m_grid.attach_next_to(m_button, m_file3, Gtk::POS_BOTTOM, 1, 1);

  m_area.set_size_request(600, 500);
  m_frame2.add(m_area);
  m_area.show();
  
  m_area.signal_draw().connect( sigc::mem_fun(*this, 
              &Input2dWindow::on_drawing));
  m_button.signal_clicked().connect( sigc::mem_fun(*this,
              &Input2dWindow::on_button_submit) );
  show_all_children();
}

Input2dWindow::~Input2dWindow()
{

}

void Input2dWindow::on_button_submit()
{
  file_xy = m_file1.get_text();
  file_yz = m_file2.get_text();
  file_zx = m_file3.get_text();

}

bool Input2dWindow::on_drawing( const Cairo::RefPtr<Cairo::Context>& cr)
{
  Gtk::Allocation allocation = get_allocation();
  const int width = allocation.get_width();
  const int height = allocation.get_height();

  double xc, yc;
  xc = width / 2;
  yc = height / 2;
  std::valarray< double > dashes(2);
  dashes[0] = 6.0;
  dashes[1] = 0.0;

  cr->set_line_width(3.0);
  Edge2d e;

  for (int i = 0; i < obj.edges.size(); i++)
  {
    e = obj.edges[i];

    cr->set_source_rgb(0.0, 0.0, 0.0);
    cr->set_dash(dashes, 0.0);
    cr->move_to(xc + 50*e.v1.x, yc - 50 - 50*e.v1.y);
    cr->line_to(xc + 50*e.v2.x, yc - 50 - 50*e.v2.y);
    cr->stroke();
  }
  
  return true;
}

Input3dWindow::Input3dWindow()
: m_button("Project"),
  m_frame1("Input for Projection"),
  m_frame2("2D Projection"),
  m_box(Gtk::ORIENTATION_VERTICAL)

{
  set_border_width(10);
  set_size_request(1000, 200);
  set_title("Input 3D object file");

  m_filename.set_max_length(50);
  m_filename.set_text("Enter file name");
  m_filename.select_region(0, m_filename.get_text_length());

  m_dir_x.set_max_length(40);
  m_dir_x.set_text("x component of projection direction");
  m_dir_x.select_region(0, m_dir_x.get_text_length());

  m_dir_y.set_max_length(40);
  m_dir_y.set_text("y component of projection direction");
  m_dir_y.select_region(0, m_dir_y.get_text_length());

  m_dir_z.set_max_length(40);
  m_dir_z.set_text("z component of projection direction");
  m_dir_z.select_region(0, m_dir_z.get_text_length());

  add(m_box);

  m_box.pack_start(m_frame1, Gtk::PACK_SHRINK, 10);
  m_box.pack_start(m_frame2, Gtk::PACK_EXPAND_WIDGET, 10);

  m_frame1.add(m_grid);
  
  m_grid.add(m_filename);
  m_grid.attach_next_to(m_dir_x, m_filename, Gtk::POS_BOTTOM, 1, 1);
  m_grid.attach_next_to(m_dir_y, m_dir_x, Gtk::POS_RIGHT, 1, 1);
  m_grid.attach_next_to(m_dir_z, m_dir_y, Gtk::POS_RIGHT, 1, 1);
  m_grid.attach_next_to(m_button, m_dir_x, Gtk::POS_BOTTOM, 1, 1);

  m_area.set_size_request(600, 500);
  m_frame2.add(m_area);
  m_area.show();

  m_area.signal_draw().connect( sigc::mem_fun(*this, 
              &Input3dWindow::on_drawing));
  m_button.signal_clicked().connect( sigc::mem_fun(*this,
              &Input3dWindow::on_button_submit) );
  // cout << filename << endl;
  show_all_children();
}

Input3dWindow::~Input3dWindow()
{

}

void Input3dWindow::on_button_submit()
{
  filename = m_filename.get_text();
  double x = stod(m_dir_x.get_text());
  double y = stod(m_dir_y.get_text());
  double z = stod(m_dir_z.get_text());
  vector<double> dir;
  dir.push_back(x);
  dir.push_back(y);
  dir.push_back(z);

  file_handle f = file_handle(filename);
  object3d project = f.input3d();
  projection p;
  p.solid = project;
  p.direction = dir;
  p.project();

  obj = p.proj;
  m_area.queue_draw();

}

bool Input3dWindow::on_drawing( const Cairo::RefPtr<Cairo::Context>& cr)
{
  Gtk::Allocation allocation = get_allocation();
  const int width = allocation.get_width();
  const int height = allocation.get_height();

  double xc, yc;
  xc = width / 2;
  yc = height / 2;
  std::valarray< double > dashes(2);
  dashes[0] = 6.0;
  dashes[1] = 3.0;

  cr->set_line_width(3.0);
  Edge2d e;

  for (int i = 0; i < obj.edges.size(); i++)
  {
    e = obj.edges[i];

    if(e.hidden)
      dashes[1] = 3.0;
    else
      dashes[1] = 0;

    cr->set_source_rgb(0.0, 0.0, 0.0);
    cr->set_dash(dashes, 0.0);
    cr->move_to(xc + 50*e.v1.x, yc - 50 - 50*e.v1.y);
    cr->line_to(xc + 50*e.v2.x, yc - 50 - 50*e.v2.y);
    cr->stroke();
  }
  
  return true;
}
