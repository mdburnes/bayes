#ifndef BAYES_BAYESDATA_HH
#define BAYES_BAYESDATA_HH

#include <string>
#define HYPOTHESIS 0.05
#define EVIDENCE_GIVEN_H 0.80
#define EVIDENCE_GIVEN_NOT_H 0.40
#define SCALE_MIN 0.001
#define SCALE_MAX 0.999
#define DOUBLE_ERROR -1

#include <iostream>

class BayesData {
  private:
    // The calculations
	double hyp_ev, hyp_nev;
	// hyp   = P(H) = 1 - P(￢H)
	// nhyp = P(￢H) = 1 - P(H)
	double hyp, nhyp;
	// ev_hyp  = P(E|H) = 1 - P(￢E|H)
	// nev_hyp = P(￢E|H) = 1 - P(E|H)
	double ev_hyp, nev_hyp;
	// ev_nhyp  = P(E|￢H) = 1 - P(￢E|￢H)
	// nev_nhyp = P(￢E|￢H) = 1 - P(E|￢H)
	double ev_nhyp, nev_nhyp;
	double text_to_double( std::string str );
  public:
	BayesData();
	void set_hyp( double value );
	void set_ev_hyp( double value );
	void set_ev_nhyp( double value );
	std::string set_hyp( std::string str );
	std::string get_hyp( void );
	double get_hyp_value( void ) { return hyp; }
	std::string set_nhyp( std::string str );
	std::string get_nhyp( void );
	double get_nhyp_value( void ) { return nhyp; }
	std::string set_ev_hyp( std::string str );
	std::string get_ev_hyp( void );
	double get_ev_hyp_value( void ) { return ev_hyp; }
	std::string set_ev_nhyp( std::string str );
	std::string get_ev_nhyp( void );
	double get_ev_nhyp_value( void ) { return ev_nhyp; }
	std::string set_nev_hyp( std::string str );
	std::string get_nev_hyp( void );
	double get_nev_hyp_value( void ) { return nev_hyp; }
	std::string set_nev_nhyp( std::string str );
	std::string get_nev_nhyp( void );
	double get_nev_nhyp_value( void ) { return nev_nhyp; }
	void set_hyp_ev( void );
	std::string get_hyp_ev( void );
	void set_hyp_nev( void );
	std::string get_hyp_nev( void );
};

#endif