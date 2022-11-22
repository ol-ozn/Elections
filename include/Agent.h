#pragma once
#include <vector>

class SelectionPolicy;
class Simulation;

class Agent
{
public:
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);
    Agent(const Agent &other); //copy constructor
    Agent(Agent &&other) noexcept; //move constructor
    Agent(int agentId, int partyId, const Agent &other);
    virtual ~Agent(); //destructor
    Agent &operator=(const Agent &other); //copy assignment operator
    Agent &operator=(Agent &&other) noexcept; //move assignment operator


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
