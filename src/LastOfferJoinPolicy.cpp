#include "JoinPolicy.h"

int LastOfferJoinPolicy::join(const vector<Agent> &offers, const Graph &graph) 
{
   return offers[offers.size() - 1].getId();
}

JoinPolicy *LastOfferJoinPolicy::clone()
{
    return new LastOfferJoinPolicy();
}