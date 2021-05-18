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
	void force_redraw( void );
  protected:
	Gtk::Box window_box, inputs_box, controls_box;
	Gtk::ButtonBox result_button_box;
	Gtk::Grid geometry_grid, hypothesis_grid, n_hypothesis_grid;
	Gtk::Grid calculations_grid;
	Gtk::Label hyp_ev_label, hyp_nev_label;
	Gtk::Label hyp_label, nhyp_label;
	Gtk::Label ev_hyp_label, ev_nhyp_label;
	Gtk::Label nev_hyp_label, nev_nhyp_label;
	Gtk::Entry hyp_ev_entry, hyp_nev_entry;
	Gtk::Entry hyp_entry, nhyp_entry;
	Gtk::Entry ev_hyp_entry, ev_nhyp_entry;
	Gtk::Entry nev_hyp_entry, nev_nhyp_entry;
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
	void on_positive_evidence_clicked( void );
	void on_negative_evidence_clicked( void );
  public:
	MainWindow( void );
	~MainWindow();
};

#endif
