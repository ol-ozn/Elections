#pragma once
#include <string>
#include <vector>
#include "Agent.h"

using std::string;
using std::vector;

class JoinPolicy;
class Simulation;

enum State
{
    Waiting,
    CollectingOffers,
    Joined
};

class Party
{
public:
    Party(int id, string name, int mandates, JoinPolicy *); 
    Party(const Party &other); //copy constructor
    Party(Party &&other); //move constructor
    virtual ~Party(); //destructor
    Party &operator=(const Party &other); //copy assignment operator
    Party &operator=(Party &&other); //move assignment operator

    State getState() const;
    void setState(State state);
    int getMandates() const;
    void step(Simulation &s);
    const string &getName() const;
    void recieveOffer(const Agent &agent);
    bool coalitionOffered(int coalitionId);

private:
    int mId;
    string mName;
    int mMandates;
    JoinPolicy *mJoinPolicy;
    State mState;
    int iteration;
    vector<Agent> offers;
};
