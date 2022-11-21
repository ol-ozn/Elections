#include "Party.h"
#include "JoinPolicy.h"
#include "Simulation.h"

Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting), iteration(0), offers()
{
    // You can change the implementation of the constructor, but not the signature!
}

Party::Party(const Party &other) : mId(other.mId), mName(other.mName), mMandates(other.mMandates), mState(other.mState), iteration(other.iteration), offers(other.offers)
{
    // mId = other.mId;
    // mName = other.mName;
    // mMandates = other.mMandates;
    // mState = other.mState;
    // iteration = other.iteration;
    // offers = other.offers;
    if(dynamic_cast<MandatesJoinPolicy*>(other.mJoinPolicy))
    {
        mJoinPolicy = new MandatesJoinPolicy();
    }
    else 
    {
        mJoinPolicy = new LastOfferJoinPolicy();
    }
}
Party::Party(Party &&other) : mId(other.mId), mName(other.mName), mMandates(other.mMandates), mState(other.mState), iteration(other.iteration), offers(other.offers), mJoinPolicy(other.mJoinPolicy)
{
    // mId = other.mId;
    // mName = other.mName;
    // mMandates = other.mMandates;
    // mState = other.mState;
    // iteration = other.iteration;
    // offers = other.offers;
    // mJoinPolicy = other.mJoinPolicy;
    other.mJoinPolicy = nullptr;
}
Party::~Party()
{
    offers.clear();
    if(mJoinPolicy)
    {
        delete mJoinPolicy;
        mJoinPolicy = nullptr;
    }
}
Party &Party::operator=(const Party &other)
{
    if(this != &other)
    {
        mId = other.mId;
        mName = other.mName;
        mMandates = other.mMandates;
        mState = other.mState;
        iteration = other.iteration;
        offers = other.offers;
        
        *mJoinPolicy = *other.mJoinPolicy;
    }

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

void Party::step(Simulation &s)
{
    if(mState == CollectingOffers) //collecting offers!
    {
        if(iteration == 2)
        {
            Agent chosenAgent = s.getAgents()[mJoinPolicy->join(offers, s.getGraph())];
            s.agents_pushBack(Agent(s.getAgents().size(), mId, chosenAgent));    
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
    
    if(mState == Waiting)
        mState = CollectingOffers;

    offers.push_back(agent); 
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

