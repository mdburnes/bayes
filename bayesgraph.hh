#ifndef BAYES_BAYESGRAPH_HH
#define BAYES_BAYESGRAPH_HH

#include "cairomm/refptr.h"
#define RIGHT_MARGIN 10
#define LEFT_MARGIN 10
#define TOP_MARGIN 10
#define BOTTOM_MARGIN 10
#define DIVIDER 3

#include <gtkmm/drawingarea.h>

class BayesGraph : public Gtk::DrawingArea {
  private:
    void draw_rectangle( const Cairo::RefPtr<Cairo::Context> &cr,
		int left, int top, int right, int bottom,
		double red, double green, double blue );
  protected:
	bool on_draw( const Cairo::RefPtr<Cairo::Context> &cr );
  public:
	BayesGraph() {};
};

#endif