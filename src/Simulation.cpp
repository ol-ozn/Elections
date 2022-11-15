#include "Simulation.h"

Simulation::Simulation(Graph graph, vector<Agent> agents) : mGraph(graph), mAgents(agents) 
{
    // You can change the implementation of the constructor, but not the signature!
}

void Simulation::step()
{
    // TODO: implement this method
    
    //iterate over parties (vertices)
    //party::step()

    vector<Party> parties = mGraph.getParties();
    for(Party party : parties) 
    {
        party.step(*this);
    }

    //iterate over agaents
    //agent::step()

    for(Agent agent : mAgents) 
    {
        agent.step(*this);
    }
}

bool Simulation::shouldTerminate() const
{
    // TODO implement this method

    //check if any coalition has 61 mandates --- IN SEPERATE PRIVATE FUNCTION
    //iterate over colationsVetor(get func down bellow)
    //iterate over each vector, sum mandates. if >= 61 , return true;
    
    //check if all parties are in state JOINED --- IN SEPERATE PRIVATE FUNCTION
    //iterate over vertices
    //if(currParty.state != Joined) return false;

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

/// This method returns a "coalition" vector, where each element is a vector of party IDs in the coalition.
/// At the simulation initialization - the result will be [[agent0.partyId], [agent1.partyId], ...]
const vector<vector<int>> Simulation::getPartiesByCoalitions() const
{
    // TODO: you MUST implement this method for getting proper output, read the documentation above.

    //create vector<vector<int>> coalitions
    //iterate over agents -
    // if colaitionVector.length < coalitionId -> colationVector.append( vector [append[agent0.Id.partyID]])
    //else coalitionVector[coalitionId].append([cuurAgent,its'party])

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

    return coalitions; //return coalitions
}
