#include "myarea.h"
#include <cairomm/context.h>
//#include "backend_header.h"


MyArea::MyArea()
{
}


MyArea::~MyArea()
{
}

bool MyArea::on_draw( const Cairo::RefPtr<Cairo::Context>& cr)
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
    cr->move_to(xc + 80*e.v1.x, yc - 80*e.v1.y);
    cr->line_to(xc + 80*e.v2.x, yc - 80*e.v2.y);
    cr->stroke();
    
  }
  

  return true;
}