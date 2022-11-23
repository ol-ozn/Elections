#include "SelectionPolicy.h"

int EdgeWeightSelectionPolicy::select(int agentPartyId, int agentCoalitionId, const Graph &graph)
{
    int heaviestEdge = 0;
    int candidateId = -1;
    for(int i = 0; i < graph.getNumVertices(); i++)
    {       
        int currEdgeWeight = graph.getEdgeWeight(agentPartyId, i);
        if(currEdgeWeight > heaviestEdge)
        {
            Party party = graph.getParty(i);
            if(party.getState() != Joined && !party.coalitionOffered(agentCoalitionId))
            {
                heaviestEdge = currEdgeWeight;
                candidateId = i;
            }
        }
    }

    return candidateId;
}

SelectionPolicy *EdgeWeightSelectionPolicy::clone()
{
    return new EdgeWeightSelectionPolicy();
}