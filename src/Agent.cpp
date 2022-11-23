#include "Agent.h"
#include "SelectionPolicy.h"
#include "Simulation.h"

Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy), mCoalitionId(agentId)
{
    // You can change the implementation of the constructor, but not the signature!
}

Agent::Agent(const Agent &other) : mAgentId(other.mAgentId), mPartyId(other.mPartyId), mSelectionPolicy(),mCoalitionId(other.mCoalitionId)
{
    mSelectionPolicy = other.mSelectionPolicy->clone();
}

Agent::Agent(Agent &&other) noexcept : mAgentId(other.mAgentId), mPartyId(other.mPartyId), mSelectionPolicy(other.mSelectionPolicy), mCoalitionId(other.mCoalitionId)  
{
    other.mSelectionPolicy = nullptr;
}

Agent::Agent(int agentId, int partyId, const Agent &other) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(), mCoalitionId(other.mCoalitionId)
{
    mSelectionPolicy = other.mSelectionPolicy->clone();
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

Agent &Agent::operator=(Agent &&other) noexcept
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
    int candidateId = mSelectionPolicy->select(mPartyId, mCoalitionId, sim.getGraph()); 
    Party &party3 = sim.getParty2(candidateId);
    if(candidateId > -1)
        party3.recieveOffer(*this);
}

