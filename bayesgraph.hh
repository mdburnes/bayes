#ifndef BAYES_BAYESGRAPH_HH
#define BAYES_BAYESGRAPH_HH

#define RIGHT_MARGIN 10
#define LEFT_MARGIN 10
#define TOP_MARGIN 10
#define BOTTOM_MARGIN 10
#define DIVIDER 3
#define BG_R 0.1
#define BG_G 0.1
#define BG_B 0.1
#define LINE_R 1.0
#define LINE_G 1.0
#define LINE_B 1.0
#define NE_H_R 0.0
#define NE_H_G 0.5
#define NE_H_B 0.0
#define E_H_R 0.0
#define E_H_G 0.0
#define E_H_B 0.5
#define NE_NH_R 0.5
#define NE_NH_G 0.0
#define NE_NH_B 0.0
#define E_NH_R 0.0
#define E_NH_G 0.0
#define E_NH_B 0.5

#include "cairomm/refptr.h"
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