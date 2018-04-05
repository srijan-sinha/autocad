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
  object2d obj;

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
  Gtk::Entry m_file1, m_file2, m_file3;
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