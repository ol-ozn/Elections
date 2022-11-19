#include "SelectionPolicy.h"
#include <iostream>  //REMOVE

//arguments: currAgent.partyId ,sim.getGraph()
//returns: Party
Party *EdgeWeightSelectionPolicy::select(int agentPartyId, int agentCoalitionId, const Graph &graph)
{
    /* if edge > 0
        Vectore<Party> possiblPartiesToOffer = fetch neighbors of party with partyId (copy)
        check validity of offer to the party (check state, check if colalition already offered..)
        if invalid -> delete from possible parties to offer
        sort the possibleParties by edge weight
        return the possibleParties[last] = best
  */
    Party *candidate = nullptr;
    int heaviestEdge = 0;
    for(int i = 0; i < graph.getNumVertices(); i++)
    {
            if(graph.getEdgeWeight(agentPartyId, i) > heaviestEdge)
            {
                Party party = graph.getParty(i);
                if(isValidCandidate(party, agentCoalitionId))
                    *candidate = party;
            }
    }
    return candidate;
}

bool EdgeWeightSelectionPolicy::isValidCandidate(Party &party, int coalitionId)
{
    std::cout << "EdgeWeightSelectionPolicy::isValidCandidate" << std::endl; //REMOVE
}