#include "Agent.h"

Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy)
{
    // You can change the implementation of the constructor, but not the signature!
}

int Agent::getId() const
{
    return mAgentId;
}

int Agent::getPartyId() const
{
    return mPartyId;
}

void Agent::step(Simulation &sim)
{
    // TODO: implement this method
    /*
    bool offerCompleted = false;
    vector<partyID> sortedNeighbors = sortNeighbors(const reference sim.graph)
    iterate neighbor parties by selection method as long as offerCOmpleted = false;
        offerCompleted = party.recieveOffer() (NEW FUNTION)

    */
}

/*
vector<partyId> Agent::sortNeighbors(Graph &graph) 
{
    vector<partyId> sortedNeighbors;
    if(selectionPolicy = E) {
        //stopped here
    } else {

    }


}

*/
