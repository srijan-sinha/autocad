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
  m_button_scale("Scale"),
  m_button_trans("Translate"),
  m_frame1("Input for Creating 3D"),
  m_frame2("Rotate 3D figure"),
  m_frame3("3D Wireframe Output"),
  m_button_r("Rotate Right"),
  m_button_l("Rotate Left"),
  m_button_u("Rotate Up"),
  m_button_d("Rotate Down"),
  m_box(Gtk::ORIENTATION_VERTICAL)

{
  set_border_width(10);
  set_size_request(1000, 200);
  set_title("Input 2D object file");

  m_file1.set_max_length(50);
  m_file1.set_text("test2_0.txt");
  m_file1.select_region(0, m_file1.get_text_length());

  m_file2.set_max_length(50);
  m_file2.set_text("test2_1.txt");
  m_file2.select_region(0, m_file2.get_text_length());

  m_file3.set_max_length(50);
  m_file3.set_text("test2_2.txt");
  m_file3.select_region(0, m_file3.get_text_length());

  m_dir_x.set_max_length(40);
  m_dir_x.set_text("10");
  m_dir_x.select_region(0, m_dir_x.get_text_length());

  m_dir_y.set_max_length(40);
  m_dir_y.set_text("5");
  m_dir_y.select_region(0, m_dir_y.get_text_length());

  m_dir_z.set_max_length(40);
  m_dir_z.set_text("12");
  m_dir_z.select_region(0, m_dir_z.get_text_length());

  m_scale.set_max_length(40);
  m_scale.set_text("Scale factor");
  m_scale.select_region(0, m_scale.get_text_length());

  m_trans_x.set_max_length(40);
  m_trans_x.set_text("x dir");
  m_trans_x.select_region(0, m_trans_x.get_text_length());

  m_trans_y.set_max_length(40);
  m_trans_y.set_text("y dir");
  m_trans_y.select_region(0, m_trans_y.get_text_length());
  
  m_trans_z.set_max_length(40);
  m_trans_z.set_text("z dir");
  m_trans_z.select_region(0, m_trans_z.get_text_length());
  
  m_trans_amount.set_max_length(40);
  m_trans_amount.set_text("trans amt");
  m_trans_amount.select_region(0, m_trans_amount.get_text_length());
  
  add(m_box);

  m_box.pack_start(m_frame1, Gtk::PACK_SHRINK, 10);
  m_box.pack_start(m_frame2, Gtk::PACK_EXPAND_WIDGET, 10);
  m_box.pack_start(m_frame3, Gtk::PACK_EXPAND_WIDGET, 10);
  
  m_frame1.add(m_grid1);
  m_frame2.add(m_grid2);

  m_grid1.add(m_file1);
  m_grid1.attach_next_to(m_file2, m_file1, Gtk::POS_RIGHT, 1, 1);
  m_grid1.attach_next_to(m_file3, m_file2, Gtk::POS_RIGHT, 1, 1);

  m_grid1.attach_next_to(m_dir_x, m_file1, Gtk::POS_BOTTOM, 1, 1);
  m_grid1.attach_next_to(m_dir_y, m_file2, Gtk::POS_BOTTOM, 1, 1);
  m_grid1.attach_next_to(m_dir_z, m_file3, Gtk::POS_BOTTOM, 1, 1);
  m_grid1.attach_next_to(m_button, m_dir_x, Gtk::POS_BOTTOM, 1, 1);

  m_grid2.add(m_button_l);
  m_grid2.attach_next_to(m_button_r, m_button_l, Gtk::POS_RIGHT, 1, 1);
  m_grid2.attach_next_to(m_button_u, m_button_r, Gtk::POS_RIGHT, 1, 1);
  m_grid2.attach_next_to(m_button_d, m_button_u, Gtk::POS_RIGHT, 1, 1);

  m_grid2.attach_next_to(m_scale, m_button_d, Gtk::POS_RIGHT, 1, 1);
  m_grid2.attach_next_to(m_button_scale, m_scale, Gtk::POS_RIGHT, 1, 1);

  m_grid2.attach_next_to(m_trans_x, m_button_scale, Gtk::POS_RIGHT, 1, 1);
  m_grid2.attach_next_to(m_trans_y, m_trans_x, Gtk::POS_BOTTOM, 1, 1);
  m_grid2.attach_next_to(m_trans_z, m_trans_y, Gtk::POS_BOTTOM, 1, 1);
  m_grid2.attach_next_to(m_trans_amount, m_trans_x, Gtk::POS_RIGHT, 1, 1);
  m_grid2.attach_next_to(m_button_trans, m_trans_amount, Gtk::POS_BOTTOM, 1, 1);

  m_area.set_size_request(600, 500);
  m_frame3.add(m_area);
  m_area.show();
  
  m_area.signal_draw().connect( sigc::mem_fun(*this, 
              &Input2dWindow::on_drawing));
  m_button.signal_clicked().connect( sigc::mem_fun(*this,
              &Input2dWindow::on_button_submit) );
  m_button_l.signal_clicked().connect( sigc::mem_fun(*this,
              &Input2dWindow::on_button_left) );
  m_button_r.signal_clicked().connect( sigc::mem_fun(*this,
              &Input2dWindow::on_button_right) );
  m_button_u.signal_clicked().connect( sigc::mem_fun(*this,
              &Input2dWindow::on_button_up) );
  m_button_d.signal_clicked().connect( sigc::mem_fun(*this,
              &Input2dWindow::on_button_down) );
  m_button_scale.signal_clicked().connect( sigc::mem_fun(*this,
              &Input2dWindow::on_button_scale) );
  m_button_trans.signal_clicked().connect( sigc::mem_fun(*this,
              &Input2dWindow::on_button_trans) );
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
  double x = stod(m_dir_x.get_text());
  double y = stod(m_dir_y.get_text());
  double z = stod(m_dir_z.get_text());
  // vector<double> dir;
  dir.push_back(x);
  dir.push_back(y);
  dir.push_back(z);

  file_handle f0 = file_handle(file_xy);
  object2d p0 = f0.input2d();
  file_handle f1 = file_handle(file_yz);
  object2d p1 = f1.input2d();
  file_handle f2 = file_handle(file_zx);
  object2d p2 = f2.input2d();
  rev_3dto2d r;
  vector<Vertex3d> v = r.cor_vertex(p0,p1,p2);
  vector<Edge3d> e = r.cor_edges(p0,p1,p2,v);

  obj.edges = e;
  obj.vertices = v;
  // projection p;
  p.solid = obj;
  p.direction = dir;
  p.project();
  proje = p.proj;
  cout<<dir.size()<<endl;
  m_area.queue_draw();
}

void Input2dWindow::on_button_right()
{
  double angle =0.01;
  // dir[0] = dir[0] + amt;
  
  p.direction = dir;
  // cout<<p.solid.edges.size()<<endl;
  // cout<<p.solid.vertices.size()<<endl;
  vector<double> d;
  d.push_back(0);
  d.push_back(0);
  d.push_back(1);

  for (int i = 0; i < obj.vertices.size(); ++i)
  {

      // cout<<obj.vertices[i].x<<" "<<obj.vertices[i].y<<" "<<obj.vertices[i].z<<"    ";
      obj.vertices[i].rotate(d,angle);
      // cout<<obj.vertices[i].x<<" "<<obj.vertices[i].y<<" "<<obj.vertices[i].z<<" "<<obj.vertices[i].name<<endl;
  }
  for (int i = 0; i < obj.edges.size(); ++i)
  {
      obj.edges[i].rotate(d,angle);
  }
  p.solid = obj;
  p.project();
  proje = p.proj;
  m_area.queue_draw();
}

void Input2dWindow::on_button_left()
{
 double angle =0.01;
  // dir[0] = dir[0] + amt;
  
  p.direction = dir;
  // cout<<p.solid.edges.size()<<endl;
  // cout<<p.solid.vertices.size()<<endl;
  vector<double> d;
  d.push_back(0);
  d.push_back(0);
  d.push_back(-1);

  for (int i = 0; i < obj.vertices.size(); ++i)
  {

      // cout<<obj.vertices[i].x<<" "<<obj.vertices[i].y<<" "<<obj.vertices[i].z<<"    ";
      obj.vertices[i].rotate(d,angle);
      // cout<<obj.vertices[i].x<<" "<<obj.vertices[i].y<<" "<<obj.vertices[i].z<<" "<<obj.vertices[i].name<<endl;
  }
  for (int i = 0; i < obj.edges.size(); ++i)
  {
      obj.edges[i].rotate(d,angle);
  }
  p.solid = obj;
  p.project();
  proje = p.proj;
  m_area.queue_draw(); 
}

void Input2dWindow::on_button_up()
{
  double angle =0.01;
  // dir[0] = dir[0] + amt;
  
  p.direction = dir;
  // cout<<p.solid.edges.size()<<endl;
  // cout<<p.solid.vertices.size()<<endl;
  vector<double> d;
  d.push_back(1);
  d.push_back(0);
  d.push_back(0);

  for (int i = 0; i < obj.vertices.size(); ++i)
  {

      // cout<<obj.vertices[i].x<<" "<<obj.vertices[i].y<<" "<<obj.vertices[i].z<<"    ";
      obj.vertices[i].rotate(d,angle);
      // cout<<obj.vertices[i].x<<" "<<obj.vertices[i].y<<" "<<obj.vertices[i].z<<" "<<obj.vertices[i].name<<endl;
  }
  for (int i = 0; i < obj.edges.size(); ++i)
  {
      obj.edges[i].rotate(d,angle);
  }
  p.solid = obj;
  p.project();
  proje = p.proj;
  m_area.queue_draw();
}

void Input2dWindow::on_button_down()
{
  double angle =0.01;
  // dir[0] = dir[0] + amt;
  
  p.direction = dir;
  // cout<<p.solid.edges.size()<<endl;
  // cout<<p.solid.vertices.size()<<endl;
  vector<double> d;
  d.push_back(-1);
  d.push_back(0);
  d.push_back(0);

  for (int i = 0; i < obj.vertices.size(); ++i)
  {

      // cout<<obj.vertices[i].x<<" "<<obj.vertices[i].y<<" "<<obj.vertices[i].z<<"    ";
      obj.vertices[i].rotate(d,angle);
      // cout<<obj.vertices[i].x<<" "<<obj.vertices[i].y<<" "<<obj.vertices[i].z<<" "<<obj.vertices[i].name<<endl;
  }
  for (int i = 0; i < obj.edges.size(); ++i)
  {
      obj.edges[i].rotate(d,angle);
  }
  p.solid = obj;
  p.project();
  proje = p.proj;
  m_area.queue_draw();
}

void Input2dWindow::on_button_scale()
{
  double factor = stod(m_scale.get_text());
  for (int i = 0; i < obj.vertices.size(); ++i)
  {

      // cout<<obj.vertices[i].x<<" "<<obj.vertices[i].y<<" "<<obj.vertices[i].z<<"    ";
      obj.vertices[i].scale(factor);
      // cout<<obj.vertices[i].x<<" "<<obj.vertices[i].y<<" "<<obj.vertices[i].z<<" "<<obj.vertices[i].name<<endl;
  }
  for (int i = 0; i < obj.edges.size(); ++i)
  {
      obj.edges[i].scale(factor);
  }
  p.solid = obj;
  p.project();
  proje = p.proj;
  m_area.queue_draw(); 
}

void Input2dWindow::on_button_trans()
{
  double dir_x = stod(m_trans_x.get_text());
  double dir_y = stod(m_trans_y.get_text());
  double dir_z = stod(m_trans_z.get_text());
  double amt = stod(m_trans_amount.get_text());
  vector<double> d;
  d.push_back(dir_x);
  d.push_back(dir_y);
  d.push_back(dir_z);

  for (int i = 0; i < obj.vertices.size(); ++i)
  {

      // cout<<obj.vertices[i].x<<" "<<obj.vertices[i].y<<" "<<obj.vertices[i].z<<"    ";
      obj.vertices[i].translate(d,amt);
      // cout<<obj.vertices[i].x<<" "<<obj.vertices[i].y<<" "<<obj.vertices[i].z<<" "<<obj.vertices[i].name<<endl;
  }
  for (int i = 0; i < obj.edges.size(); ++i)
  {
      obj.edges[i].translate(d,amt);
  }
  p.solid = obj;
  p.project();
  proje = p.proj;
  m_area.queue_draw(); 
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

  for (int i = 0; i < proje.edges.size(); i++)
  {
    e = proje.edges[i];

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
