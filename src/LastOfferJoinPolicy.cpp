#include "JoinPolicy.h"

//argument: const &Vector<Agent>
//returns: Agent
int LastOfferJoinPolicy::join(const vector<Agent> &offers, const Graph &graph) 
{
   return offers[offers.size() - 1].getId();
}