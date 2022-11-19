#include "Party.h"
#include "JoinPolicy.h"
#include "Simulation.h"
#include <iostream>

Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting), iteration(-1), offers()
{
    // You can change the implementation of the constructor, but not the signature!

    //init those v in the init list
        //int iteration = -1
        //vector<agent> offers
}

//DONT FORGET RULE OF 5

Party::Party(const Party &other)
{
    mId = other.mId;
    mName = other.mName;
    mMandates = other.mMandates;
    mState = other.mState;
    iteration = other.iteration;
    offers = other.offers;
    mJoinPolicy = dynamic_cast<JoinPolicy*>(other.mJoinPolicy); // A = new B(); --MIGHT FAIL
}
Party::Party(Party &&other)
{
    mId = other.mId;
    mName = other.mName;
    mMandates = other.mMandates;
    mState = other.mState;
    iteration = other.iteration;
    offers = other.offers;
    mJoinPolicy = other.mJoinPolicy;
    other.mJoinPolicy = nullptr;
}
Party::~Party()
{
    // if(mJoinPolicy)
    //     {
    //         delete mJoinPolicy;
    //         mJoinPolicy = nullptr;
    //     }
    std::cout << "~Party()" <<std::endl;
}
Party &Party::operator=(const Party &other)
{
    mId = other.mId;
    mName = other.mName;
    mMandates = other.mMandates;
    mState = other.mState;
    iteration = other.iteration;
    offers = other.offers;
    *mJoinPolicy = *(other.mJoinPolicy);
    return *this;
}
Party &Party::operator=(Party &&other)
{
    mId = other.mId;
    mName = other.mName;
    mMandates = other.mMandates;
    mState = other.mState;
    iteration = other.iteration;
    offers = other.offers;
    if(mJoinPolicy)
        delete mJoinPolicy;
    mJoinPolicy = other.mJoinPolicy;
    other.mJoinPolicy = nullptr;
    return *this;
}


State Party::getState() const
{
    return mState;
}

void Party::setState(State state)
{
    mState = state;
}

int Party::getMandates() const
{
    return mMandates;
}

const string & Party::getName() const
{
    return mName;
}

//getOffersVector() const Function

void Party::step(Simulation &s)
{
    if(mState == Waiting)
    {
        if(iteration == 3)
        {
            Agent chosenAgent = mJoinPolicy->join(offers, s.getGraph());            
            s.agents_pushBack(Agent(s.getGraph().getNumVertices(), mId, chosenAgent));            
            mState = Joined;
        }
        else
        {
            iteration++;
        }
    }
}

void Party::recieveOffer(const Agent &agent)
{
    
    offers.push_back(agent);
    
    if(mState == Waiting)
        mState = CollectingOffers;
}


bool Party::coalitionOffered(int coalitionId)
{
    for(Agent agent : offers)
    {
        if(agent.getCoalitionId() == coalitionId)
            return true;
    }
    return false;
}

