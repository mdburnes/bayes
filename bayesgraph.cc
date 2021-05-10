#include "bayesgraph.hh"

#include <cairomm/context.h>

bool BayesGraph::on_draw( const Cairo::RefPtr<Cairo::Context> &cr ) {
	Gtk::Allocation allocation = get_allocation();
	int margin = 10;
	int right = allocation.get_width() - margin * 2;
	int bottom = allocation.get_height() - margin * 2;
	int left = margin;
	int top = margin;
	cr->set_source_rgb(0.1, 0.1, 0.1);
	cr->move_to(left, top);
	cr->line_to(right, top);
	cr->line_to(right, bottom);
	cr->line_to(left, bottom);
	cr->line_to(left, top);
	cr->fill();
	return true;
}