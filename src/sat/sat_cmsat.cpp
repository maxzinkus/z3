#include "sat_cmsat.h"
using namespace sat;

cmsolver::cmsolver(reslimit& l) :
    solver_core(l)
{}

cmsolver::~cmsolver() {}

void cmsolver::pop_to_base_level() {}
bool cmsolver::at_base_lvl() const { return true; }

// retrieve model if solver return sat
sat::model const & cmsolver::get_model() const {
    sat::model x;
    return x;
}

// retrieve core from assumptions
literal_vector const& cmsolver::get_core() const {
}

// is the state inconsistent?
bool cmsolver::inconsistent() const
{}

// number of variables and clauses
unsigned cmsolver::num_vars() const
{
    return solver.nVars();
}

unsigned cmsolver::num_clauses() const
{
    //msoos: I could implment this, but I'm curious why it's important.
    //msoos: Let me pick this up.
    return 10000;
}

// check satisfiability
lbool cmsolver::check(unsigned num_lits, literal const* lits)
{}

char const* cmsolver::get_reason_unknown()
{}

// add clauses
void cmsolver::add_clause(unsigned n, literal* lits, bool is_redundant)
{}

void cmsolver::add_clause(literal l1, literal l2, bool is_redundant)
{}

void cmsolver::add_clause(literal l1, literal l2, literal l3, bool is_redundant)
{}

// create boolean variable, tagged as external (= true) or internal (can be eliminated).
bool_var cmsolver::add_var(bool ext)
{}

// update parameters
void cmsolver::updt_params(params_ref const& p)
{}


bool cmsolver::check_invariant() const
{}

void cmsolver::display_status(std::ostream& out) const
{}

void cmsolver::display_dimacs(std::ostream& out) const
{}

bool cmsolver::is_external(bool_var v) const
{}

bool cmsolver::is_external(literal l) const
{}

void cmsolver::set_external(bool_var v)
{}

void cmsolver::set_non_external(bool_var v)
{}

void cmsolver::set_eliminated(bool_var v, bool f)
{}


// The following methods are used when converting the state from the SAT solver back
// to a set of assertions.

// retrieve model converter that handles variable elimination and other transformations
void cmsolver::flush(model_converter& mc)
{}

// size of initial trail containing unit clauses
unsigned cmsolver::init_trail_size() const
{}

// literal at trail index i
literal cmsolver::trail_literal(unsigned i) const
{}

// collect n-ary clauses
clause_vector const& cmsolver::clauses() const
{}

// collect binary clauses
void cmsolver::collect_bin_clauses(svector<bin_clause> & r, bool learned, bool learned_only) const
{}

// collect statistics from sat solver
void cmsolver::collect_statistics(statistics & st) const
{}
