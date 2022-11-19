#include "JoinPolicy.h"

//argument: const &Vector<Agent>
//returns: Agent
Agent LastOfferJoinPolicy::join(const vector<Agent> &offers, const Graph &graph) 
{
   return offers[offers.size() - 1];
}