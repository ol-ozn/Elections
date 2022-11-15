#include "Agent.h"

Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy), mCoalitionId(agentId)
{
    // You can change the implementation of the constructor, but not the signature!

    //init list v
        //int colalitionId = agentId
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

int Agent::getCoalitionId() const
{
    return mCoalitionId;
}

void Agent::step(Simulation &sim)
{
    // TODO: implement this method
    /*
    bool offerCompleted = false;
    Party candidate = selectionPolicy.select(currAgent.partyId ,sim.getGraph()) 
    
    candidate.recieveOffer();

    */
   
}

