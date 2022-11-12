#include "Agent.h"

Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy)
{
    // You can change the implementation of the constructor, but not the signature!

    //init list v
        //int colalitionId = partyId
}

//create another construscor, that also recieves a coalitionId and sets coalitionId to it.

//DONT FORGET RULE OF 5!!!

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

    //explanation: the best party is the last index. if the offer is succesfull- break. if not- try the next best one (index--)
    //if no candidate- do nothing
    iterate sortedNeighbors as long as offerCOmpleted = false; 
        offerCompleted = party.recieveOffer() (NEW FUNTION)

    */
}


//DONT FORGET TO DECLARE AS PRIVATE IN THE HEADER
/*
vector<partyId> Agent::sortNeighbors(Graph &graph) 
{
    vector<partyId> sortedNeighbors;
    if(selectionPolicy = E) {
        if(w.e == 0) skip it
    } else {
        
    }


}

*/
