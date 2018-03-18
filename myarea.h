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