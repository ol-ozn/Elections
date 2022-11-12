#include "Party.h"

Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting) 
{
    // You can change the implementation of the constructor, but not the signature!

    //init those v in the init list
        //int iteration = -1
        //dict<coalitionId,offeringPartyID> offers
        //int lastOfferPartyId = -1
}

//DONT FORGET RULE OF 5

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
    // TODO: implement this method

    //if(state == waiting) do nothing
    //if(state == joinded) do nothing
    //if(state == collecting offers)
    //if(iteration == 3) join coalition according to joinPolicy
        // Agent chosenAgent = joinPolicy.join(offers)
        // s.agents.append(copy of chosenAgent)
    //else iteration++ 
}

//DONT FORGET TO DECLARE AS PRIVATE IN THE HEADER
/*void Party::recieveOffer(const Agent &agent){
    
    offers.append(agent)
    
    if(state == waiting)
        state = collectingOffers
    
}
*/
