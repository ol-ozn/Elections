#include "JoinPolicy.h"

//argument: const &Vector<Agent>
//returns: Agent
Agent LastOfferJoinPolicy::join(const vector<Agent> &offers) 
{
    /*
        return vectore[last]
    */
   return offers[offers.size() - 1];
}