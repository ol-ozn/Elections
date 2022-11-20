#include "SelectionPolicy.h"
#include <iostream>  //REMOVE

//arguments: currAgent.partyId ,sim.getGraph()
//returns: Party
int EdgeWeightSelectionPolicy::select(int agentPartyId, int agentCoalitionId, const Graph &graph)
{
    Party *candidate = nullptr;
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
                candidate = &party;
                candidateId = i;
            }
        }
    }


    return candidateId;
}