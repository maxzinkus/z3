#ifndef SAT_CMSAT_H_
#define SAT_CMSAT_H_

#include "sat_solver_core.h"
#include "cryptominisat5/cryptominisat.h"

namespace sat {
    class cmsolver : public solver_core {
        cmsolver(reslimit& l);
        virtual ~cmsolver();

        virtual void pop_to_base_level() override;
        virtual bool at_base_lvl() const override;

        // retrieve model if solver return sat
        virtual model const & get_model() const;

        // retrieve core from assumptions
        virtual literal_vector const& get_core() const;

        // is the state inconsistent?
        virtual bool inconsistent() const;

        // number of variables and clauses
        virtual unsigned num_vars() const ;
        virtual unsigned num_clauses() const;

        // check satisfiability
        virtual lbool check(unsigned num_lits = 0, literal const* lits = nullptr);

        virtual char const* get_reason_unknown();

        // add clauses
        virtual void add_clause(unsigned n, literal* lits, bool is_redundant);
        void add_clause(literal l1, literal l2, bool is_redundant);
        void add_clause(literal l1, literal l2, literal l3, bool is_redundant);

        // create boolean variable, tagged as external (= true) or internal (can be eliminated).
        virtual bool_var add_var(bool ext);

        // update parameters
        virtual void updt_params(params_ref const& p);


        virtual bool check_invariant() const;
        virtual void display_status(std::ostream& out) const;
        virtual void display_dimacs(std::ostream& out) const;

        virtual bool is_external(bool_var v) const;
        bool is_external(literal l) const;
        virtual void set_external(bool_var v);
        virtual void set_non_external(bool_var v);
        virtual void set_eliminated(bool_var v, bool f);

        // optional support for user-scopes. Not relevant for sat_tactic integration.
        // it is only relevant for incremental mode SAT, which isn't wrapped (yet)
//         virtual void user_push() { throw default_exception("optional API not supported"); }
//         virtual void user_pop(unsigned num_scopes) {};
        //virtual unsigned num_user_scopes();

        // hooks for extension solver. really just ba_solver atm.
//         virtual extension* get_extension() const { return nullptr; }
//         virtual void       set_extension(extension* e) { if (e) throw default_exception("optional API not supported"); }


        // The following methods are used when converting the state from the SAT solver back
        // to a set of assertions.

        // retrieve model converter that handles variable elimination and other transformations
        virtual void flush(model_converter& mc);

        // size of initial trail containing unit clauses
        virtual unsigned init_trail_size() const;

        // literal at trail index i
        virtual literal trail_literal(unsigned i) const;

        // collect n-ary clauses
        virtual clause_vector const& clauses() const;

        // collect binary clauses
        typedef std::pair<literal, literal> bin_clause;
        virtual void collect_bin_clauses(svector<bin_clause> & r, bool learned, bool learned_only) const;

        // collect statistics from sat solver
        virtual void collect_statistics(statistics & st) const;

        CMSat::SATSolver solver;
    };

} //namespace sat


#endif //SAT_CMSAT_H_
