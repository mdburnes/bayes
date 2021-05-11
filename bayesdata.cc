#include "bayesdata.hh"

#include <string>
#include <sstream>

BayesData::BayesData() {
	hyp = HYPOTHESIS;
	nhyp = 1 - hyp;
	ev_hyp = EVIDENCE_GIVEN_H;
	nev_hyp = 1 - ev_hyp;
	ev_nhyp = EVIDENCE_GIVEN_NOT_H;
	nev_nhyp = 1 - ev_nhyp;
}

double BayesData::text_to_double( std::string str ) {
	double working_number = atof(str.c_str());
	if( working_number <= 0 || working_number >= 1 ) return DOUBLE_ERROR;
	return working_number;
}

double BayesData::set_hyp( double value ) {
	if( value <= 0 || value >= 1 ) return hyp;
	hyp = value;
	nhyp = 1 - value;
	return hyp;
}

std::string BayesData::set_hyp( std::string str ) {
	std::stringstream s_str;
	double working_number = text_to_double( str );
	if( working_number == DOUBLE_ERROR ) working_number = hyp;
	hyp = working_number;
	nhyp = 1 - working_number;
	s_str << hyp;
	return s_str.str();
}

std::string BayesData::get_hyp( void ) {
	std::stringstream s_str;
	s_str << hyp;
	return s_str.str();
}

std::string BayesData::set_nhyp( std::string str ) {
	std::stringstream s_str;
	double working_number = text_to_double( str );
	if( working_number == DOUBLE_ERROR ) working_number = nhyp;
	nhyp = working_number;
	hyp = 1 - working_number;
	s_str << nhyp;
	return s_str.str();
}

std::string BayesData::get_nhyp( void ) {
	std::stringstream s_str;
	s_str << nhyp;
	return s_str.str();
}

std::string BayesData::set_ev_hyp( std::string str ) {
	std::stringstream s_str;
	double working_number = text_to_double( str );
	if( working_number == DOUBLE_ERROR ) working_number = ev_hyp;
	ev_hyp = working_number;
	nev_hyp = 1 - working_number;
	s_str << ev_hyp;
	return s_str.str();
}

std::string BayesData::get_ev_hyp( void ) {
	std::stringstream s_str;
	s_str << ev_hyp;
	return s_str.str();
}

std::string BayesData::set_ev_nhyp( std::string str ) {
	std::stringstream s_str;
	double working_number = text_to_double( str );
	if( working_number == DOUBLE_ERROR ) working_number = ev_nhyp;
	ev_nhyp = working_number;
	nev_nhyp = 1 - working_number;
	s_str << ev_nhyp;
	return s_str.str();
}

std::string BayesData::get_ev_nhyp( void ) {
	std::stringstream s_str;
	s_str << ev_nhyp;
	return s_str.str();
}

std::string BayesData::set_nev_hyp( std::string str ) {
	std::stringstream s_str;
	double working_number = text_to_double( str );
	if( working_number == DOUBLE_ERROR ) working_number = nev_hyp;
	nev_hyp = working_number;
	ev_hyp = 1 - working_number;
	s_str << nev_hyp;
	return s_str.str();
}

std::string BayesData::get_nev_hyp( void ) {
	std::stringstream s_str;
	s_str << nev_hyp;
	return s_str.str();
}

std::string BayesData::set_nev_nhyp( std::string str ) {
	std::stringstream s_str;
	double working_number = text_to_double( str );
	if( working_number == DOUBLE_ERROR ) working_number = nev_nhyp;
	nev_nhyp = working_number;
	ev_nhyp = 1 - working_number;
	s_str << nev_nhyp;
	return s_str.str();
}

std::string BayesData::get_nev_nhyp( void ) {
	std::stringstream s_str;
	s_str << nev_nhyp;
	return s_str.str();
}
