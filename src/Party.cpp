#include "Party.h"
#include "JoinPolicy.h"
#include "Simulation.h"
#include <iostream>
#include "SelectionPolicy.h" // ROMOVE
Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting), iteration(-1), offers()
{
    // You can change the implementation of the constructor, but not the signature!
    std::cout << "constructor: " << mName << mJoinPolicy << std::endl; 
}

Party::Party(const Party &other)
{
    mId = other.mId;
    mName = other.mName;
    mMandates = other.mMandates;
    mState = other.mState;
    iteration = other.iteration;
    offers = other.offers;
    std::cout << "copy const: " << mName << " previous address: " << mJoinPolicy << std::endl; 
    // mJoinPolicy = dynamic_cast<JoinPolicy*>(other.mJoinPolicy); // A = new B(); --MIGHT FAIL
    if(dynamic_cast<MandatesJoinPolicy*>(other.mJoinPolicy))
    {
        std::cout<< "dynamic type is mandates " << std::endl;
        mJoinPolicy = new MandatesJoinPolicy();
    }
    else 
    {
        std::cout<< "dynamic type is last offer " << std::endl;
        mJoinPolicy = new LastOfferJoinPolicy();
    }
    std::cout << "copy const: " << mName << " new address: " << mJoinPolicy << std::endl; 

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
    std::cout << "move constructor: " << mName << this <<std::endl;

}
Party::~Party()
{
    std::cout << "~Party()" <<std::endl;
    // std::cout << mName <<std::endl;
    std::cout << "trying to delete: " << mName << mJoinPolicy <<std::endl;
    if(mJoinPolicy)
    {
        delete mJoinPolicy;
        mJoinPolicy = nullptr;
    }
    std::cout << "exiting ~party()  address: " << mJoinPolicy << std::endl;
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
    std::cout << "assignment op: " << mName << "address: " << mJoinPolicy << std::endl; 

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
    std::cout << "move operator: " << mName << this <<std::endl;
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
    if(mState == Waiting) //collecting offers!
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
    
    if(mState == Waiting)
        mState = CollectingOffers;

    offers.push_back(agent); //
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

