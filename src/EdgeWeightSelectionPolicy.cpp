#include "SelectionPolicy.h"

//arguments: currAgent.partyId ,sim.getGraph()
//returns: Party
Party EdgeWeightSelectionPolicy::select(int agentPartyId, int agentCoalitionId, const Graph &graph)
{
    /* if edge > 0
        Vectore<Party> possiblPartiesToOffer = fetch neighbors of party with partyId (copy)
        check validity of offer to the party (check state, check if colalition already offered..)
        if invalid -> delete from possible parties to offer
        sort the possibleParties by edge weight
        return the possibleParties[last] = best
    */
};