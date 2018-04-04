// direction data of the object
// 2d object rendering all orthographic views if possible
// 3d object refresh rate rendering

#include <string>
#ifndef GTKMM_EXAMPLE_MYAREA_H
#define GTKMM_EXAMPLE_MYAREA_H
#include "backend_header.h"
#include <gtkmm/drawingarea.h>

class MyArea : public Gtk::DrawingArea
{
public:
	object2d obj;
  
  MyArea();
  virtual ~MyArea();

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
  Gtk::Box m_Box;
  Gtk::Frame m_Frame;
  Gtk::Grid m_Grid1, m_Grid2;
  Gtk::Button m_Button_2d_3d, m_Button_3d_2d;
};

class Input2dWindow : public Gtk::Window
{
public:
  Input2dWindow();
  virtual ~Input2dWindow();
  string filename;

protected:
  //Signal Handlers
  void on_button_submit();

  //Child Widgets:
  Gtk::Box m_box;
  Gtk::Frame m_frame;
  Gtk::Grid m_grid;
  Gtk::Button m_button;
  Gtk::Entry m_entry;
};

class Input3dWindow : public Gtk::Window
{
public:
  Input3dWindow();
  virtual ~Input3dWindow();
  string filename;

protected:
  //Signal Handlers
  void on_button_submit();

  //Child Widgets:
  Gtk::Box m_box;
  Gtk::Frame m_frame;
  Gtk::Grid m_grid;
  Gtk::Button m_button;
  Gtk::Entry m_entry;
};

#endif //GTKMM_EXAMPLEWINDOW_H