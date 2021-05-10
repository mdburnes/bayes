#ifndef BAYES_BAYESGRAPH_HH
#define BAYES_BAYESGRAPH_HH

#include <gtkmm/drawingarea.h>

class BayesGraph : public Gtk::DrawingArea {
  protected:
	bool on_draw( const Cairo::RefPtr<Cairo::Context> &cr );
  public:
	BayesGraph() {};
};

#endif