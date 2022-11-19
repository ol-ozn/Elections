#include "Agent.h"
#include "SelectionPolicy.h"
#include "Simulation.h"

Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy), mCoalitionId(agentId)
{
    // You can change the implementation of the constructor, but not the signature!

    //init list v
        //int colalitionId = agentId
}

//create another construscor, that also recieves a coalitionId and sets coalitionId to it.

Agent::Agent(const Agent &other)
{
    mAgentId = other.getId();
    mPartyId = other.getPartyId();
    mSelectionPolicy = dynamic_cast<SelectionPolicy*>(other.getSelectionPolicy()); // A = new B(); --MIGHT FAIL
    mCoalitionId = other.getCoalitionId();
}

Agent::Agent(Agent &&other)
{
    mAgentId = other.getId();
    mPartyId = other.getPartyId();
    mCoalitionId = other.getCoalitionId();
    mSelectionPolicy = other.mSelectionPolicy;
    other.mSelectionPolicy = nullptr;
}

Agent::Agent(int agentId, int partyId, const Agent &other) : mAgentId(agentId), mPartyId(mPartyId)
{
    mSelectionPolicy = dynamic_cast<SelectionPolicy*>(other.getSelectionPolicy());
    mCoalitionId = other.mCoalitionId;
}

Agent::~Agent()
{
    if(mSelectionPolicy)
    {
        delete mSelectionPolicy;
        mSelectionPolicy = nullptr;
    }
}

Agent &Agent::operator=(const Agent &other)
{
    mAgentId = other.getId();
    mPartyId = other.getPartyId();
    mCoalitionId = other.getCoalitionId();
    *mSelectionPolicy = *(other.mSelectionPolicy);
    return *this;
}

Agent &Agent::operator=(Agent &&other)
{
    mAgentId = other.getId();
    mPartyId = other.getPartyId();
    mCoalitionId = other.getCoalitionId();
    if(mSelectionPolicy)
        delete mSelectionPolicy;
    mSelectionPolicy = other.mSelectionPolicy;
    other.mSelectionPolicy = nullptr;
    return *this;
}

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

SelectionPolicy *Agent::getSelectionPolicy() const
{
    return mSelectionPolicy;
}

void Agent::step(Simulation &sim)
{
    // TODO: implement this method
    /*
    bool offerCompleted = false;
    Party candidate = selectionPolicy.select(currAgent.partyId ,sim.getGraph()) 
    
    candidate.recieveOffer();

    */
    Party candidate = mSelectionPolicy->select(mPartyId, mCoalitionId, sim.getGraph()); 
    candidate.recieveOffer(*this);
}

