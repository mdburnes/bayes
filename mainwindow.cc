#include "mainwindow.hh"
#include "gtkmm/adjustment.h"
#include "gtkmm/box.h"
#include "gtkmm/enums.h"
#include "gtkmm/scale.h"
#include "pangomm/layout.h"
#include "sigc++/functors/mem_fun.h"

#include <iostream>

MainWindow::MainWindow( void )
:
  window_box( Gtk::ORIENTATION_HORIZONTAL, 10 ),
  inputs_box( Gtk::ORIENTATION_HORIZONTAL, 10 ),
  controls_box( Gtk::ORIENTATION_VERTICAL, 10 ),
  geometry_grid(),
  hypothesis_grid(),
  n_hypothesis_grid(),
  hyp_label( "P(H)", Gtk::ALIGN_END ),
  n_hyp_label( "P(￢H)", Gtk::ALIGN_END ),
  ev_given_hyp_label( "P(E|H)", Gtk::ALIGN_END ),
  ev_given_n_hyp_label( "P(E|￢H)", Gtk::ALIGN_END ),
  neg_ev_given_hyp_label( "P(￢E|H)", Gtk::ALIGN_END ),
  neg_ev_given_n_hyp_label( "P￢E|￢H)", Gtk::ALIGN_END ),
  eh_scale_adjustment( Gtk::Adjustment::create(0.0, 0.0, 1.0, 0.01, 0, 0) ),
  neh_scale_adjustment( Gtk::Adjustment::create(0.0, 0.0, 1.0, 0.01, 0, 0) ),
  phe_scale_adjustment( Gtk::Adjustment::create(0.0, 0.0, 1.0, 0.01, 0, 0) ),
  eh_scale( Gtk::ORIENTATION_VERTICAL ),
  neh_scale( Gtk::ORIENTATION_VERTICAL ),
  phe_scale( Gtk::ORIENTATION_HORIZONTAL ),
  positive_evidence( "Positive" ),
  negative_evidence( "Negative" )
 	{
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
	result_button_box.set_halign( Gtk::ALIGN_END );
	result_button_box.set_valign( Gtk::ALIGN_END );

	eh_scale.set_digits( 3 );
	eh_scale.set_draw_value( true );
	eh_scale.set_can_focus( true );
	eh_scale.set_adjustment( eh_scale_adjustment );
	eh_scale.set_inverted( true );
	eh_scale.set_size_request( -1, 300 );
	eh_scale.set_vexpand( false );
	eh_scale.set_hexpand( false );
	neh_scale.set_digits( 3 );
	neh_scale.set_draw_value( true );
	neh_scale.set_can_focus( true );
	neh_scale.set_adjustment( neh_scale_adjustment );
	neh_scale.set_inverted( true );
	neh_scale.set_size_request( -1, 300 );
	neh_scale.set_vexpand( false );
	neh_scale.set_hexpand( false );
	phe_scale.set_digits( 3 );
	phe_scale.set_draw_value( true );
	phe_scale.set_can_focus( true );
	phe_scale.set_adjustment( phe_scale_adjustment );
	phe_scale.set_size_request( 300, -1 );
	phe_scale.set_vexpand( false );
	phe_scale.set_hexpand( false );
	drawing_area.set_size_request(300, 300);
	drawing_area.set_hexpand( true );
	drawing_area.set_vexpand( true );

	hyp_label.set_can_focus( false );
	ev_given_hyp_label.set_can_focus( false );
	neg_ev_given_hyp_label.set_can_focus( false );
	hyp_entry.set_can_focus( true );
	ev_given_hyp_entry.set_can_focus( true );
	neg_ev_given_hyp_entry.set_can_focus( true );
	n_hyp_label.set_can_focus( false );
	ev_given_n_hyp_label.set_can_focus ( false );
	neg_ev_given_n_hyp_label.set_can_focus( false );
	n_hyp_entry.set_can_focus( true );
	ev_given_n_hyp_entry.set_can_focus( true );
	neg_ev_given_n_hyp_entry.set_can_focus( true );

	geometry_grid.attach( eh_scale, 0, 0 );
	geometry_grid.attach( drawing_area, 1, 0 );
	geometry_grid.attach( neh_scale, 2, 0 );
	geometry_grid.attach( phe_scale, 1, 1 );

	hypothesis_grid.attach( hyp_label, 0, 0 );
	hypothesis_grid.attach( ev_given_hyp_label, 0, 1 );
	hypothesis_grid.attach( neg_ev_given_hyp_label, 0, 2 );
	hypothesis_grid.attach( hyp_entry, 1, 0 );
	hypothesis_grid.attach( ev_given_hyp_entry, 1, 1 );
	hypothesis_grid.attach( neg_ev_given_hyp_entry, 1, 2 );

	n_hypothesis_grid.attach( n_hyp_label, 0, 0 );
	n_hypothesis_grid.attach( ev_given_n_hyp_label, 0, 1 );
	n_hypothesis_grid.attach( neg_ev_given_n_hyp_label, 0, 2 );
	n_hypothesis_grid.attach( n_hyp_entry, 1, 0 );
	n_hypothesis_grid.attach( ev_given_n_hyp_entry, 1, 1 );
	n_hypothesis_grid.attach( neg_ev_given_n_hyp_entry, 1, 2 );

	result_button_box.pack_start( positive_evidence,
								Gtk::PACK_EXPAND_WIDGET, 10 );
	result_button_box.pack_start( negative_evidence,
								Gtk::PACK_EXPAND_WIDGET, 10 );

	window_box.pack_start( geometry_grid, Gtk::PACK_EXPAND_WIDGET, 10 );
	inputs_box.pack_start( hypothesis_grid, Gtk::PACK_EXPAND_WIDGET, 10 );
	inputs_box.pack_start( n_hypothesis_grid, Gtk::PACK_EXPAND_WIDGET, 10 );
	controls_box.pack_start( inputs_box, Gtk:: PACK_EXPAND_WIDGET, 10 );
	controls_box.pack_start( result_button_box,
							Gtk::PACK_EXPAND_WIDGET, 10 );
	window_box.pack_start( controls_box, Gtk::PACK_EXPAND_WIDGET, 10 );

	add( window_box );
	show_all_children();

	eh_scale.signal_value_changed().connect(
		sigc::mem_fun(this, &MainWindow::on_eh_scale_changed)
	);
}

MainWindow::~MainWindow() {
}

void MainWindow::on_eh_scale_changed( void ) {
	// std::cout << "Value changed" << std::endl;
}