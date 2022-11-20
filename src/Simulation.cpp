#include "Simulation.h"
#include <iostream>

Simulation::Simulation(Graph graph, vector<Agent> agents) : mGraph(graph), mAgents(agents) 
{
    // You can change the implementation of the constructor, but not the signature!
}

void Simulation::step()
{
    std::cout << "simulation:step" << std::endl;
    // vector<Party> parties = mGraph.getParties();
    for(Party party : mGraph.getParties()) //party shallow copies, fix: change to explicit for loop
    {
        party.step(*this);
    }

    for(Agent agent : mAgents) 
    {
        agent.step(*this);
    }
}

bool Simulation::shouldTerminate() const
{
    return allPartiesJoined() || anyCoalitionOver60();
}

bool Simulation::allPartiesJoined() const
{
    return mAgents.size() == mGraph.getNumVertices();
}

bool Simulation::anyCoalitionOver60() const
{
    vector<vector<int>> coalitions = getPartiesByCoalitions();
    
    for(vector<int> coalition : coalitions)
    {
        int sum = 0;
        for(int party : coalition)
        {
            sum += mGraph.getParty(party).getMandates();
        }
        if(sum >= 61)
            return true;
    }
    return false;
}

const Graph &Simulation::getGraph() const
{
    return mGraph;
}

const vector<Agent> &Simulation::getAgents() const
{
    return mAgents;
}

const Party &Simulation::getParty(int partyId) const
{
    return mGraph.getParty(partyId);
}

 Party &Simulation::getParty2(int partyId) 
{
    return mGraph.getParty2(partyId);
}

/// This method returns a "coalition" vector, where each element is a vector of party IDs in the coalition.
/// At the simulation initialization - the result will be [[agent0.partyId], [agent1.partyId], ...]
const vector<vector<int>> Simulation::getPartiesByCoalitions() const
{
    vector<vector<int>> coalitions;
    for(Agent agent : mAgents) 
    {
        if(coalitions.size() <= agent.getCoalitionId()) 
        {
            vector<int> coalitionsParties = {agent.getPartyId()};
            coalitions.push_back(coalitionsParties);
        } 
        else 
        {
            coalitions[agent.getCoalitionId()].push_back(agent.getPartyId());
        }
    }

    return coalitions;
}

void Simulation::agents_pushBack(const Agent &&agent)
{
    mAgents.push_back(agent);
}
