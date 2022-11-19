#pragma once

#include <vector>

// #include "Graph.h"

class SelectionPolicy;
class Simulation;

class Agent
{
public:
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);
    Agent(const Agent &other); //copy constructor
    Agent(Agent &&other); //move constructor
    Agent(int agentId, int partyId, const Agent &other);
    virtual ~Agent(); //destructor
    Agent &operator=(const Agent &other); //copy assignment operator
    Agent &operator=(Agent &&other); //move assignment operator


    int getPartyId() const;
    int getId() const;
    void step(Simulation &s);
    int getCoalitionId() const;
    SelectionPolicy *getSelectionPolicy() const;

private:
    int mAgentId;
    int mPartyId;
    SelectionPolicy *mSelectionPolicy;
    int mCoalitionId;
};
