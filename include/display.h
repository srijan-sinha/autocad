// direction data of the object
// 2d object rendering all orthographic views if possible
// 3d object refresh rate rendering

#include <string>
#ifndef GTKMM_EXAMPLE_MYAREA_H
#define GTKMM_EXAMPLE_MYAREA_H
#include "backend_header.h"
#include "file_handle.h"
#include <gtkmm/drawingarea.h>

class MyArea : public Gtk::DrawingArea
{
public:
  MyArea();
  virtual ~MyArea();
  object2d obj;

protected:
  //Override default signal handler:
  bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;
};

#endif // GTKMM_EXAMPLE_MYAREA_H

#ifndef GTKMM_EXAMPLEWINDOW_H
#define GTKMM_EXAMPLEWINDOW_H

#include <gtkmm.h>

class MainWindow : public Gtk::Window
{
public:
  MainWindow();
  virtual ~MainWindow();

protected:
  //Signal Handlers:
  void on_button_2d_3d();
  void on_button_3d_2d();

  //Child widgets:
  Gtk::Box m_box;
  Gtk::Frame m_frame;
  Gtk::Grid m_grid1, m_grid2;
  Gtk::Button m_button_2d_3d, m_button_3d_2d;
};

class Input2dWindow : public Gtk::Window
{
public:
  Input2dWindow();
  virtual ~Input2dWindow();
  string file_xy;
  string file_yz;
  string file_zx;
  object3d obj;
  vector<double> dir;
  object2d proje;
  projection p;

protected:
  //Signal Handlers
  void on_button_submit();
  void on_button_right();
  void on_button_left();
  void on_button_up();
  void on_button_down();
  void on_button_scale();
  void on_button_trans();
  bool on_drawing( const Cairo::RefPtr<Cairo::Context>& cr);

  //Child Widgets:
  Gtk::DrawingArea m_area;
  Gtk::Box m_box;
  Gtk::Frame m_frame1, m_frame2, m_frame3;
  Gtk::Grid m_grid1, m_grid2;
  Gtk::Button m_button, m_button_r, m_button_l, m_button_u, m_button_d, m_button_scale, m_button_trans;
  Gtk::Entry m_file1, m_file2, m_file3, m_dir_x, m_dir_y, m_dir_z, m_scale, m_trans_x, m_trans_y, m_trans_z, m_trans_amount;
};

class Input3dWindow : public Gtk::Window
{
public:
  Input3dWindow();
  virtual ~Input3dWindow();
  object2d obj;
  string filename;

protected:
  //Signal Handlers
  void on_button_submit();
  bool on_drawing( const Cairo::RefPtr<Cairo::Context>& cr);

  //Child Widgets:
  Gtk::DrawingArea m_area;
  Gtk::Box m_box;
  Gtk::Frame m_frame1, m_frame2;
  Gtk::Grid m_grid;
  Gtk::Button m_button;
  Gtk::Entry m_filename, m_dir_x, m_dir_y, m_dir_z;
};

#endif //GTKMM_EXAMPLEWINDOW_H