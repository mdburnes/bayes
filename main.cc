/// main.cc ///

#include "mainwindow.hh"
#include "bayesdata.hh"

#include <iostream>
#include <gtkmm-3.0/gtkmm/application.h>

BayesData bayes_data;

int main( int argc, char *argv[] ) {
	auto app = Gtk::Application::create( argc, argv );
	MainWindow main_window;
	return app->run( main_window );
}