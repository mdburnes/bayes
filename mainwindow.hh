#ifndef BAYES_MAINWINDOW_HH
#define BAYES_MAINWINDOW_HH

#include "bayesgraph.hh"

#include "gtkmm/container.h"
#include "gtkmm/widget.h"
#include <gtkmm/enums.h>
#include <gtkmm/window.h>
#include <gtkmm/box.h>
#include <gtkmm/buttonbox.h>
#include <gtkmm/grid.h>
#include <gtkmm/label.h>
#include <gtkmm/entry.h>
#include <gtkmm/scale.h>
#include <gtkmm/adjustment.h>
#include <gtkmm/drawingarea.h>
#include <gtkmm/button.h>

#include <string>

class MainWindow : public Gtk::Window {
  private:
	bool window_is_closing;
	float text_to_float( std::string string_to_process );
	std::string float_to_text( float float_to_process );
  protected:
	Gtk::Box window_box, inputs_box, controls_box;
	Gtk::ButtonBox result_button_box;
	Gtk::Grid geometry_grid, hypothesis_grid, n_hypothesis_grid;
	Gtk::Label hyp_label, n_hyp_label;
	Gtk::Label ev_given_hyp_label, ev_given_n_hyp_label;
	Gtk::Label neg_ev_given_hyp_label, neg_ev_given_n_hyp_label;
	Gtk::Entry hyp_entry, n_hyp_entry;
	Gtk::Entry ev_given_hyp_entry, ev_given_n_hyp_entry;
	Gtk::Entry neg_ev_given_hyp_entry, neg_ev_given_n_hyp_entry;
	Gtk::Scale eh_scale, neh_scale, phe_scale;
	Glib::RefPtr<Gtk::Adjustment> eh_scale_adjustment;
	Glib::RefPtr<Gtk::Adjustment> neh_scale_adjustment;
	Glib::RefPtr<Gtk::Adjustment> phe_scale_adjustment;
	BayesGraph bayes_graph;
	Gtk::Button positive_evidence, negative_evidence;
	bool on_delete_event( GdkEventAny *event );
	void on_phe_scale_changed( void );
	void on_eh_scale_changed( void );
	void on_neh_scale_changed( void );
	void on_hyp_entry_activate( void );
	bool on_hyp_entry_focus_out_event( GdkEventFocus *ev );
	void on_ev_given_hyp_entry_activate( void );
	bool on_ev_given_hyp_entry_focus_out_event( GdkEventFocus *ev );
	void on_neg_ev_given_hyp_entry_activate( void );
	bool on_neg_ev_given_hyp_entry_focus_out_event( GdkEventFocus *ev );
	void on_n_hyp_entry_activate( void );
	bool on_n_hyp_entry_focus_out_event( GdkEventFocus *ev );
	void on_ev_given_n_hyp_entry_activate( void );
	bool on_ev_given_n_hyp_entry_focus_out_event( GdkEventFocus *ev );
	void on_neg_ev_given_n_hyp_entry_activate( void );
	bool on_neg_ev_given_n_hyp_entry_focus_out_event( GdkEventFocus *ev );
  public:
	MainWindow( void );
	~MainWindow();
};

#endif
