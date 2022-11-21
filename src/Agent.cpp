#include "Agent.h"
#include "SelectionPolicy.h"
#include "Simulation.h"
#include <iostream>

Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy), mCoalitionId(agentId)
{
    // You can change the implementation of the constructor, but not the signature!
}

Agent::Agent(const Agent &other) : mAgentId(other.mAgentId), mPartyId(other.mPartyId), mCoalitionId(other.mCoalitionId)
{
    // mAgentId = other.getId();
    // mPartyId = other.getPartyId();
    // mCoalitionId = other.getCoalitionId();
    if(dynamic_cast<MandatesSelectionPolicy*>(other.mSelectionPolicy))
    {
        mSelectionPolicy = new MandatesSelectionPolicy();
    }
    else 
    {
        mSelectionPolicy = new EdgeWeightSelectionPolicy();
    }
}

Agent::Agent(Agent &&other) : mAgentId(other.mAgentId), mPartyId(other.mPartyId), mCoalitionId(other.mCoalitionId), mSelectionPolicy(other.mSelectionPolicy)
{
    // mAgentId = other.getId();
    // mPartyId = other.getPartyId();
    // mCoalitionId = other.getCoalitionId();
    // mSelectionPolicy = other.mSelectionPolicy;
    other.mSelectionPolicy = nullptr;
}

Agent::Agent(int agentId, int partyId, const Agent &other) : mAgentId(agentId), mPartyId(partyId), mCoalitionId(other.mCoalitionId)
{
    if(dynamic_cast<MandatesSelectionPolicy*>(other.mSelectionPolicy))
    {
        mSelectionPolicy = new MandatesSelectionPolicy();
    }
    else 
    {
        mSelectionPolicy = new EdgeWeightSelectionPolicy();
    }
    // mPartyId = partyId;
    // mCoalitionId = other.mCoalitionId;
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
    int candidateId = mSelectionPolicy->select(mPartyId, mCoalitionId, sim.getGraph()); 
    Party &party3 = sim.getParty2(candidateId);
    if(candidateId > -1)
        party3.recieveOffer(*this);
}

