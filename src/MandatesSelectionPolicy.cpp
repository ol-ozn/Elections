#include "MandatesSelectionPolicy.h"

//arguments: currAgent.partyId ,sim.getGraph()
//returns: Party
void MandatesSelectionPolicy::select()
{
    /*
        Vectore<Party> possiblPartiesToOffer = fetch neighbors of party with partyId (copy)
        check validity of offer to the party (check state, check if colalition already offered..)
        if invalid -> delete from possible parties to offer
        sort the possibleParties by mandates amount
        return the possibleParties[last] = best
    */
};