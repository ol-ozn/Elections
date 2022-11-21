#include "JoinPolicy.h"
#include "Graph.h"

int MandatesJoinPolicy::join(const vector<Agent> &offers, const Graph &graph) 
{
    int mostMandates = -1;
    int candidateId = -1;
    for(Agent candidate : offers)
    {
        int currMandates = graph.getParty(candidate.getPartyId()).getMandates();
        if(currMandates > mostMandates)
        {
            mostMandates = currMandates;
            candidateId = candidate.getId();
        }
    }

    return candidateId;
}

JoinPolicy::~JoinPolicy() = default;