#include "bayesgraph.hh"
#include "bayesdata.hh"

#include <cairomm/context.h>

extern BayesData bayes_data;

bool BayesGraph::on_draw( const Cairo::RefPtr<Cairo::Context> &cr ) {
	int hyp_width, nhyp_width;
	int ev_hyp_height, nev_hyp_height;
	int ev_nhyp_height, nev_nhyp_height;
	int rec_top, rec_left, rec_right, rec_bottom;
	int w1, w2, h1, h2;
	double red, green, blue;
	Gtk::Allocation allocation = get_allocation();
	int total_width = allocation.get_width();
	int total_height = allocation.get_height();
	int graph_width = total_width - (RIGHT_MARGIN + LEFT_MARGIN + DIVIDER);
	int graph_height = total_height - (TOP_MARGIN + BOTTOM_MARGIN + DIVIDER);
	int top = TOP_MARGIN;
	int left = LEFT_MARGIN;
	int right = total_width - RIGHT_MARGIN;
	int bottom = total_height - BOTTOM_MARGIN;
	hyp_width = graph_width * bayes_data.get_hyp_value();
	nhyp_width = graph_width * bayes_data.get_nhyp_value();
	nev_hyp_height = graph_height * bayes_data.get_nev_hyp_value();
	ev_hyp_height = graph_height * bayes_data.get_ev_hyp_value();
	nev_nhyp_height = graph_height * bayes_data.get_nev_nhyp_value();
	ev_nhyp_height = graph_height * bayes_data.get_ev_nhyp_value();

	// draw the graph background
	red = BG_R;
	green = BG_G;
	blue = BG_B;
	draw_rectangle(cr, left, top, right, bottom, red, green, blue);
	// draw the ￢e|h rectangle
	rec_top = top;
	rec_left = left;
	rec_right = hyp_width + left;
	rec_bottom = top + nev_hyp_height;
	red = NE_H_R;
	green = NE_H_G;
	blue = NE_H_B;
	draw_rectangle(cr,
		rec_left, rec_top, rec_right, rec_bottom,
		red, green, blue );
	// draw the e|h rectangle
	rec_top = top + nev_hyp_height + DIVIDER;
	rec_left = left;
	rec_right = hyp_width + left;
	rec_bottom = rec_top + ev_hyp_height;
	red = E_H_R;
	green = E_H_G;
	blue = E_H_B;
	draw_rectangle(cr,
		rec_left, rec_top, rec_right, rec_bottom,
		red, green, blue );
	// draw the ￢e|￢h rectangle
	rec_top = top;
	rec_left = left + hyp_width + DIVIDER;
	rec_bottom = top + nev_nhyp_height;
	rec_right = rec_left + nhyp_width;
	red = NE_NH_R;
	green = NE_NH_G;
	blue = NE_NH_B;
	draw_rectangle(cr,
		rec_left, rec_top, rec_right, rec_bottom,
		red, green, blue );
	// draw the e|￢h rectangle
	rec_top = top + nev_nhyp_height + DIVIDER;
	rec_left = left + hyp_width + DIVIDER;
	rec_bottom = rec_top + ev_nhyp_height;
	rec_right = rec_left + nhyp_width;
	red = E_NH_R;
	green = E_NH_G;
	blue = E_NH_B;
	draw_rectangle(cr,
		rec_left, rec_top, rec_right, rec_bottom,
		red, green, blue );
	// draw h/￢h divider
	red = LINE_R;
	green = LINE_G;
	blue = LINE_B;
	cr->set_line_width(3.0);
	cr->set_source_rgb(red, green, blue);
	h1 = top;
	w1 = w2 = left + hyp_width + 2;
	h2 = bottom;
	cr->move_to(w1, h1);
	cr->line_to(w2, h2);
	cr->stroke();
	// draw ￢e/e given h divider
	// using same line width and color as above
	w1 = left;
	w2 = w1 + hyp_width;
	h1 = h2 = top + nev_hyp_height + 2;
	cr->move_to(w1, h1);
	cr->line_to(w2, h2);
	cr->stroke();
	// draw ￢e/e given ￢h divider
	// using same line width and color as above
	w1 = left + hyp_width + DIVIDER;
	w2 = w1 + nhyp_width;
	h1 = h2 = top + nev_nhyp_height + 2;
	cr->move_to(w1, h1);
	cr->line_to(w2, h2);
	cr->stroke();
	return true;
}

void BayesGraph::draw_rectangle( const Cairo::RefPtr<Cairo::Context> &cr,
			int left, int top, int right, int bottom,
			double red, double green, double blue ) {
	cr->set_source_rgb(red, green, blue);
	cr->move_to(left, top);
	cr->line_to(right, top);
	cr->line_to(right, bottom);
	cr->line_to(left, bottom);
	cr->line_to(left, top);
	cr->fill();
}