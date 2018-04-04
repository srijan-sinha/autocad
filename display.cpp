#include "display.h"
#include <iostream>
using namespace std;

MainWindow::MainWindow()
: m_Button_2d_3d("2D to 3D"),
  m_Button_3d_2d("3D to 2D")
{
  set_border_width(30);
  set_size_request(200, 100);
  set_title("AutoCad");

  add(m_Box);
  m_Box.add(m_Grid1);
  m_Box.add(m_Grid2);
  m_Grid1.add(m_Button_2d_3d);
  m_Grid2.add(m_Button_3d_2d);

  m_Button_2d_3d.signal_clicked().connect( sigc::mem_fun(*this,
              &MainWindow::on_button_2d_3d) );
  m_Button_3d_2d.signal_clicked().connect( sigc::mem_fun(*this,
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
: m_button("Submit"),
  m_frame("Enter the file name")

{
  set_border_width(10);
  set_size_request(600, 200);
  set_title("Input 2D object file");

  m_entry.set_max_length(15);
  m_entry.set_text("Enter file name with extension .txt");
  m_entry.select_region(0, m_entry.get_text_length());

  add(m_box);

  m_box.pack_start(m_frame, Gtk::PACK_EXPAND_WIDGET, 10);
  m_frame.add(m_grid);
  m_grid.add(m_entry);
  m_grid.attach_next_to(m_button, m_entry, Gtk::POS_RIGHT, 1, 1);
  m_button.signal_clicked().connect( sigc::mem_fun(*this,
              &Input2dWindow::on_button_submit) );
  cout << filename << endl;
  show_all_children();
}

Input2dWindow::~Input2dWindow()
{

}

void Input2dWindow::on_button_submit()
{
  filename = m_entry.get_text();
}

Input3dWindow::Input3dWindow()
: m_button("Submit"),
  m_frame("Enter the file name")

{
  set_border_width(10);
  set_size_request(600, 200);
  set_title("Input 3D object file");

  m_entry.set_max_length(15);
  m_entry.set_text("Enter file name with extension .txt");
  m_entry.select_region(0, m_entry.get_text_length());

  add(m_box);

  m_box.pack_start(m_frame, Gtk::PACK_EXPAND_WIDGET, 10);
  m_frame.add(m_grid);
  m_grid.add(m_entry);
  m_grid.attach_next_to(m_button, m_entry, Gtk::POS_RIGHT, 1, 1);
  m_button.signal_clicked().connect( sigc::mem_fun(*this,
              &Input3dWindow::on_button_submit) );
  cout << filename << endl;
  show_all_children();
}

Input3dWindow::~Input3dWindow()
{

}

void Input3dWindow::on_button_submit()
{
  filename = m_entry.get_text();
}