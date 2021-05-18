#include "mainwindow.hh"
#include "bayesdata.hh"
#include "gtkmm/adjustment.h"
#include "gtkmm/box.h"
#include "gtkmm/enums.h"
#include "gtkmm/scale.h"
#include "pangomm/layout.h"
#include "sigc++/functors/mem_fun.h"

#include <iostream>
#include <string>
#include <sstream>

extern BayesData bayes_data;

MainWindow::MainWindow( void )
:
  window_box( Gtk::ORIENTATION_HORIZONTAL, 10 ),
  inputs_box( Gtk::ORIENTATION_HORIZONTAL, 10 ),
  controls_box( Gtk::ORIENTATION_VERTICAL, 10 ),
  geometry_grid(),
  hypothesis_grid(),
  n_hypothesis_grid(),
  calculations_grid(),
  hyp_ev_label( "P(H|E)", Gtk::ALIGN_END ),
  hyp_nev_label( "P(H|￢E)", Gtk::ALIGN_END ),
  hyp_label( "P(H)", Gtk::ALIGN_END ),
  nhyp_label( "P(￢H)", Gtk::ALIGN_END ),
  ev_hyp_label( "P(E|H)", Gtk::ALIGN_END ),
  ev_nhyp_label( "P(E|￢H)", Gtk::ALIGN_END ),
  nev_hyp_label( "P(￢E|H)", Gtk::ALIGN_END ),
  nev_nhyp_label( "P(￢E|￢H)", Gtk::ALIGN_END ),
  eh_scale_adjustment(Gtk::Adjustment::create(
	  0.0, SCALE_MIN, SCALE_MAX, 0.01, 0, 0) ),
  neh_scale_adjustment(Gtk::Adjustment::create(
	  0.0, SCALE_MIN, SCALE_MAX, 0.01, 0, 0) ),
  phe_scale_adjustment(Gtk::Adjustment::create(
	  0.0, SCALE_MIN, SCALE_MAX, 0.01, 0, 0) ),
  eh_scale( Gtk::ORIENTATION_VERTICAL ),
  neh_scale( Gtk::ORIENTATION_VERTICAL ),
  phe_scale( Gtk::ORIENTATION_HORIZONTAL ),
  positive_evidence( "Positive" ),
  negative_evidence( "Negative" )
 	{
	window_is_closing = false;
	window_box.set_can_focus( false );
	geometry_grid.set_can_focus( false );
	hypothesis_grid.set_can_focus( false );
	hypothesis_grid.set_valign( Gtk::ALIGN_CENTER );
	hypothesis_grid.set_row_spacing( 10 );
	hypothesis_grid.set_column_spacing( 10 );
	n_hypothesis_grid.set_can_focus( false );
	n_hypothesis_grid.set_valign( Gtk::ALIGN_CENTER );
	n_hypothesis_grid.set_row_spacing( 10 );
	n_hypothesis_grid.set_column_spacing( 10 );
	calculations_grid.set_can_focus( false );
	calculations_grid.set_valign(Gtk::ALIGN_CENTER);
	calculations_grid.set_halign(Gtk::ALIGN_CENTER);
	calculations_grid.set_row_spacing(10);
	calculations_grid.set_column_spacing(10);
	result_button_box.set_halign( Gtk::ALIGN_END );
	result_button_box.set_valign( Gtk::ALIGN_END );

	eh_scale.set_digits( 3 );
	eh_scale.set_draw_value( false );
	eh_scale.set_can_focus( true );
	eh_scale.set_adjustment( eh_scale_adjustment );
	eh_scale.set_inverted( true );
	eh_scale.set_size_request( -1, 300 );
	eh_scale.set_vexpand( false );
	eh_scale.set_hexpand( false );
	neh_scale.set_digits( 3 );
	neh_scale.set_draw_value( false );
	neh_scale.set_can_focus( true );
	neh_scale.set_adjustment( neh_scale_adjustment );
	neh_scale.set_inverted( true );
	neh_scale.set_size_request( -1, 300 );
	neh_scale.set_vexpand( false );
	neh_scale.set_hexpand( false );
	phe_scale.set_digits( 3 );
	phe_scale.set_draw_value( false );
	phe_scale.set_can_focus( true );
	phe_scale.set_adjustment( phe_scale_adjustment );
	phe_scale.set_size_request( 300, -1 );
	phe_scale.set_vexpand( false );
	phe_scale.set_hexpand( false );
	phe_scale.set_value_pos(Gtk::POS_RIGHT);
	bayes_graph.set_size_request(300, 300);
	bayes_graph.set_hexpand( true );
	bayes_graph.set_vexpand( true );

	hyp_ev_label.set_can_focus( false );
	hyp_nev_label.set_can_focus( false );
	hyp_ev_entry.set_can_focus( false );
	hyp_nev_entry.set_can_focus( false );

	hyp_label.set_can_focus( false );
	ev_hyp_label.set_can_focus( false );
	nev_hyp_label.set_can_focus( false );
	hyp_entry.set_can_focus( true );
	ev_hyp_entry.set_can_focus( true );
	nev_hyp_entry.set_can_focus( true );
	nhyp_label.set_can_focus( false );
	ev_nhyp_label.set_can_focus ( false );
	nev_nhyp_label.set_can_focus( false );
	nhyp_entry.set_can_focus( true );
	ev_nhyp_entry.set_can_focus( true );
	nev_nhyp_entry.set_can_focus( true );

	hyp_ev_entry.set_text(bayes_data.get_hyp_ev());
	hyp_nev_entry.set_text(bayes_data.get_hyp_nev());

	hyp_entry.set_text(bayes_data.get_hyp());
	ev_hyp_entry.set_text(bayes_data.get_ev_hyp());
	nev_hyp_entry.set_text(bayes_data.get_nev_hyp());
	nhyp_entry.set_text(bayes_data.get_nhyp());
	ev_nhyp_entry.set_text(bayes_data.get_ev_nhyp());
	nev_nhyp_entry.set_text(bayes_data.get_nev_nhyp());
	
	phe_scale.set_value(bayes_data.get_hyp_value());
	eh_scale.set_value(bayes_data.get_ev_hyp_value());
	neh_scale.set_value(bayes_data.get_ev_nhyp_value());


	geometry_grid.attach( eh_scale, 0, 0 );
	geometry_grid.attach( bayes_graph, 1, 0 );
	geometry_grid.attach( neh_scale, 2, 0 );
	geometry_grid.attach( phe_scale, 1, 1 );

	hypothesis_grid.attach( hyp_label, 0, 0 );
	hypothesis_grid.attach( ev_hyp_label, 0, 1 );
	hypothesis_grid.attach( nev_hyp_label, 0, 2 );
	hypothesis_grid.attach( hyp_entry, 1, 0 );
	hypothesis_grid.attach( ev_hyp_entry, 1, 1 );
	hypothesis_grid.attach( nev_hyp_entry, 1, 2 );

	n_hypothesis_grid.attach( nhyp_label, 0, 0 );
	n_hypothesis_grid.attach( ev_nhyp_label, 0, 1 );
	n_hypothesis_grid.attach( nev_nhyp_label, 0, 2 );
	n_hypothesis_grid.attach( nhyp_entry, 1, 0 );
	n_hypothesis_grid.attach( ev_nhyp_entry, 1, 1 );
	n_hypothesis_grid.attach( nev_nhyp_entry, 1, 2 );

	calculations_grid.attach(hyp_ev_label, 0, 0);
	calculations_grid.attach(hyp_nev_label, 0, 1);
	calculations_grid.attach(hyp_ev_entry, 1, 0);
	calculations_grid.attach(hyp_nev_entry, 1, 1);

	result_button_box.pack_start( positive_evidence,
								Gtk::PACK_EXPAND_WIDGET, 10 );
	result_button_box.pack_start( negative_evidence,
								Gtk::PACK_EXPAND_WIDGET, 10 );

	window_box.pack_start( geometry_grid, Gtk::PACK_EXPAND_WIDGET, 10 );
	inputs_box.pack_start( hypothesis_grid, Gtk::PACK_EXPAND_WIDGET, 10 );
	inputs_box.pack_start( n_hypothesis_grid, Gtk::PACK_EXPAND_WIDGET, 10 );
	controls_box.pack_start( inputs_box, Gtk::PACK_EXPAND_WIDGET, 10 );
	controls_box.pack_start( calculations_grid, Gtk::PACK_EXPAND_WIDGET, 10);
	controls_box.pack_start( result_button_box,
							Gtk::PACK_EXPAND_WIDGET, 10 );
	window_box.pack_start( controls_box, Gtk::PACK_EXPAND_WIDGET, 10 );

	add( window_box );
	show_all_children();

	// Connect all the signals to their slots
	phe_scale.signal_value_changed().connect(
		sigc::mem_fun(this, &MainWindow::on_phe_scale_changed));
	eh_scale.signal_value_changed().connect(
		sigc::mem_fun(this, &MainWindow::on_eh_scale_changed));
	neh_scale.signal_value_changed().connect(
		sigc::mem_fun(this, &MainWindow::on_neh_scale_changed));
	hyp_entry.signal_activate().connect(
		sigc::mem_fun(this, &MainWindow::on_hyp_entry_activate));
	hyp_entry.signal_focus_out_event().connect(
		sigc::mem_fun(this, &MainWindow::on_hyp_entry_focus_out_event));
	nhyp_entry.signal_activate().connect(
		sigc::mem_fun(this, &MainWindow::on_n_hyp_entry_activate));
	nhyp_entry.signal_focus_out_event().connect(
		sigc::mem_fun(this, &MainWindow::on_n_hyp_entry_focus_out_event));
	ev_hyp_entry.signal_activate().connect(
		sigc::mem_fun(this, &MainWindow::on_ev_given_hyp_entry_activate));
	ev_hyp_entry.signal_focus_out_event().connect(
		sigc::mem_fun(this,
		&MainWindow::on_ev_given_hyp_entry_focus_out_event));
	nev_hyp_entry.signal_activate().connect(
		sigc::mem_fun(this, &MainWindow::on_neg_ev_given_hyp_entry_activate));
	nev_hyp_entry.signal_focus_out_event().connect(
		sigc::mem_fun(this,
		&MainWindow::on_neg_ev_given_hyp_entry_focus_out_event));
	ev_nhyp_entry.signal_activate().connect(
		sigc::mem_fun(this, &MainWindow::on_ev_given_n_hyp_entry_activate));
	ev_nhyp_entry.signal_focus_out_event().connect(
		sigc::mem_fun(this,
		&MainWindow::on_ev_given_n_hyp_entry_focus_out_event));
	nev_nhyp_entry.signal_activate().connect(
		sigc::mem_fun(this,
		&MainWindow::on_neg_ev_given_n_hyp_entry_activate));
	nev_nhyp_entry.signal_focus_out_event().connect(
		sigc::mem_fun(this,
		&MainWindow::on_neg_ev_given_n_hyp_entry_focus_out_event));
	}

MainWindow::~MainWindow() {
}

void MainWindow::force_redraw( void ) {
	auto win = get_window();
	if (win)
		{
			Gdk::Rectangle r(0, 0, get_allocation().get_width(),
							 get_allocation().get_height());
			win->invalidate_rect(r, false);
		}
}

bool MainWindow::on_delete_event( GdkEventAny *event ) {
	window_is_closing = true;
	return false;
}

void MainWindow::on_phe_scale_changed( void ) {
	bayes_data.set_hyp(phe_scale.get_value());
	bayes_data.set_hyp_ev();
	bayes_data.set_hyp_nev();
	hyp_entry.set_text(bayes_data.get_hyp());
	nhyp_entry.set_text(bayes_data.get_nhyp());
	hyp_ev_entry.set_text(bayes_data.get_hyp_ev());
	hyp_nev_entry.set_text(bayes_data.get_hyp_nev());
	force_redraw();
}

void MainWindow::on_eh_scale_changed( void ) {
	bayes_data.set_ev_hyp(eh_scale.get_value());
	bayes_data.set_hyp_ev();
	bayes_data.set_hyp_nev();
	ev_hyp_entry.set_text(bayes_data.get_ev_hyp());
	nev_hyp_entry.set_text(bayes_data.get_nev_hyp());
	hyp_ev_entry.set_text(bayes_data.get_hyp_ev());
	hyp_nev_entry.set_text(bayes_data.get_hyp_nev());
	force_redraw();
}

void MainWindow::on_neh_scale_changed( void ) {
	bayes_data.set_ev_nhyp(neh_scale.get_value());
	bayes_data.set_hyp_ev();
	bayes_data.set_hyp_nev();
	ev_nhyp_entry.set_text(bayes_data.get_ev_nhyp());
	nev_nhyp_entry.set_text(bayes_data.get_nev_nhyp());
	hyp_ev_entry.set_text(bayes_data.get_hyp_ev());
	hyp_nev_entry.set_text(bayes_data.get_hyp_nev());
	force_redraw();
}

void MainWindow::on_hyp_entry_activate( void ) {
	hyp_entry.set_text(bayes_data.set_hyp(hyp_entry.get_text()));
	nhyp_entry.set_text(bayes_data.get_nhyp());
	phe_scale.set_value(bayes_data.get_hyp_value());
}

bool MainWindow::on_hyp_entry_focus_out_event( GdkEventFocus *ev ) {
	if(window_is_closing) return false;
	hyp_entry.set_text(bayes_data.set_hyp(hyp_entry.get_text()));
	nhyp_entry.set_text(bayes_data.get_nhyp());
	phe_scale.set_value(bayes_data.get_hyp_value());
	return false;
}

void MainWindow::on_ev_given_hyp_entry_activate( void ) {
	ev_hyp_entry.set_text(
		bayes_data.set_ev_hyp(ev_hyp_entry.get_text()));
	nev_hyp_entry.set_text(bayes_data.get_nev_hyp());
	eh_scale.set_value(bayes_data.get_ev_hyp_value());
}

bool MainWindow::on_ev_given_hyp_entry_focus_out_event( GdkEventFocus *ev ) {
	if(window_is_closing) return false;
	ev_hyp_entry.set_text(
		bayes_data.set_ev_hyp(ev_hyp_entry.get_text()));
	nev_hyp_entry.set_text(bayes_data.get_nev_hyp());
	eh_scale.set_value(bayes_data.get_ev_hyp_value());
	return false;
}

void MainWindow::on_neg_ev_given_hyp_entry_activate( void ) {
	nev_hyp_entry.set_text(
		bayes_data.set_nev_hyp(nev_hyp_entry.get_text()));
	ev_hyp_entry.set_text(bayes_data.get_ev_hyp());
	eh_scale.set_value(bayes_data.get_ev_hyp_value());
}

bool MainWindow::on_neg_ev_given_hyp_entry_focus_out_event(GdkEventFocus *ev) {
	if(window_is_closing) return false;
	nev_hyp_entry.set_text(
		bayes_data.set_nev_hyp(nev_hyp_entry.get_text()));
	ev_hyp_entry.set_text(bayes_data.get_ev_hyp());
	eh_scale.set_value(bayes_data.get_ev_hyp_value());
	return false;
}

void MainWindow::on_n_hyp_entry_activate( void ) {
	nhyp_entry.set_text(bayes_data.set_nhyp(nhyp_entry.get_text()));
	hyp_entry.set_text(bayes_data.get_hyp());
	phe_scale.set_value(bayes_data.get_hyp_value());
}

bool MainWindow::on_n_hyp_entry_focus_out_event( GdkEventFocus *ev ) {
	if(window_is_closing) return false;
	nhyp_entry.set_text(bayes_data.set_nhyp(nhyp_entry.get_text()));
	hyp_entry.set_text(bayes_data.get_hyp());
	phe_scale.set_value(bayes_data.get_hyp_value());
	return false;
}

void MainWindow::on_ev_given_n_hyp_entry_activate( void ) {
	ev_nhyp_entry.set_text(
		bayes_data.set_ev_nhyp(ev_nhyp_entry.get_text()));
	nev_nhyp_entry.set_text(bayes_data.get_nev_nhyp());
	neh_scale.set_value(bayes_data.get_ev_nhyp_value());
}

bool MainWindow::on_ev_given_n_hyp_entry_focus_out_event(GdkEventFocus *ev) {
	if(window_is_closing) return false;
	ev_nhyp_entry.set_text(
		bayes_data.set_ev_nhyp(ev_nhyp_entry.get_text()));
	nev_nhyp_entry.set_text(bayes_data.get_nev_nhyp());
	neh_scale.set_value(bayes_data.get_ev_nhyp_value());
	return false;
}

void MainWindow::on_neg_ev_given_n_hyp_entry_activate( void ) {
	nev_nhyp_entry.set_text(
		bayes_data.set_nev_nhyp(nev_nhyp_entry.get_text()));
	ev_nhyp_entry.set_text(bayes_data.get_ev_nhyp());
	neh_scale.set_value(bayes_data.get_ev_nhyp_value());
}

bool MainWindow::
on_neg_ev_given_n_hyp_entry_focus_out_event(GdkEventFocus *ev) {
	if(window_is_closing) return false;
	nev_nhyp_entry.set_text(
		bayes_data.set_nev_nhyp(nev_nhyp_entry.get_text()));
	ev_nhyp_entry.set_text(bayes_data.get_ev_nhyp());
	neh_scale.set_value(bayes_data.get_ev_nhyp_value());
	return false;
}