#include "Party.h"

Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting) 
{
    // You can change the implementation of the constructor, but not the signature!
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
    // TODO: implement this method

    //if(state == waiting) do nothing
    //if(state == joinded) do nothing
    //if(state == collecting offers)
    //if(iteration == 3) join coalition according to joinPolicy
        //join coaltion: if JP = L ->  s.getAgents(where agent.partyID == lastOfferPartyId).append(copy agent())
        //else JP = M -> iterate over offers and take max mandates party
    //else iterion++ 
}

/*bool Party::recieveOffer(int coalitionId, int offeringPartyId){
    if(state == joined) -  return false;
    else 
        if(offers.contains(coalitionId)) -  return false;
        else
            offers[coalitionId] = offeringPartyID
            lastOfferPID = partyid
            if(state == waiting)
                state = collectingOffers
            return true;
}
*/
