// Copyright (C) 2009, 2010 by Florent Lamiraux, Thomas Moulard, JRL.
//
// This file is part of the hpp-affordance-corba.
//
// This software is provided "as is" without warranty of any kind,
// either expressed or implied, including but not limited to the
// implied warranties of fitness for a particular purpose.
//
// See the COPYING file for more information.

#ifndef HPP_AFFORDANCE_CORBA_IMPL_HH
# define HPP_AFFORDANCE_CORBA_IMPL_HH
# include <omniORB4/CORBA.h>
# include <hpp/fcl/BVH/BVH_model.h>
# include "hpp/core/problem-solver.hh"
# include "hpp/corbaserver/affordance/fwd.hh"

# include "affordance.hh"

namespace hpp
{
  namespace affordanceCorba
  {
    namespace impl
    {
      class Afford : public virtual
      POA_hpp::corbaserver::affordance::Afford
      {
      public:

	      Afford ();

				Afford (const core::ProblemSolverPtr_t& problemSolver);

	      void setProblemSolver (const ProblemSolverPtr_t& problemSolver);

				affordance::OperationBases_t createOperations ();

				void affordanceAnalysis (const char* obstacleName, 
					const affordance::OperationBases_t & operations) throw (hpp::Error);

				void analyseObject (const char* obstacleName) throw (hpp::Error);
				
				void analyseAll () throw (hpp::Error);

				void deleteAffordancesByType (const char* affordance,
					const char* obstacleName) throw (hpp::Error);

					void deleteAffordances (const char* obstacleName)
						throw (hpp::Error);

				void addAffObjects (const affordance::OperationBases_t& ops,
					const std::vector<affordance::CollisionObjects_t>& affObjs,
					const char* obstacleName) 
					throw (hpp::Error);
				
				hpp::doubleSeqSeqSeqSeq* getAffordancePoints (const char* affordance)
					throw (hpp::Error);

      private:
	      core::ProblemSolverPtr_t problemSolver_;
      }; // class Afford
    } // namespace impl
  } // namespace affordanceCorba
} // namespace hpp

#endif //HPP_AFFORDANCE_CORBA_IMPL_HH
