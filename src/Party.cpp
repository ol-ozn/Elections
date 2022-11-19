#include "Party.h"
#include "JoinPolicy.h"
#include "Simulation.h"

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
    if(mJoinPolicy)
        {
            delete mJoinPolicy;
            mJoinPolicy = nullptr;
        }
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
    // TODO: implement this method

    //if(state == waiting) do nothing
    //if(state == joinded) do nothing
    //if(state == collecting offers)
    //if(iteration == 3) join coalition according to joinPolicy
        // Agent chosenAgent = joinPolicy.join(offers)
        // s.agents.append(copy of chosenAgent)
    //else iteration++ 
    
    if(mState == Waiting)
    {

    } 
    else if(mState == Joined)
    {

    } 
    else //collecting offers
    {
        if(iteration == 3)
        {
            //previous
            Agent chosenAgent = mJoinPolicy->join(offers);

            //int chosenAgentParyID = joinPolicy.join(agentsPartyIds,parties)
            //Agent chosenAgent = agent that has chosenAgentPartyId
            //s.agents.push_back(Agent(chosenAgent) -> copy)
            
            s.agents_pushBack(Agent(s.getGraph().getNumVertices(), mId, chosenAgent));
            //STOPPED HEREEEEEEE
            
        }
    }
}

//DONT FORGET TO DECLARE AS PRIVATE IN THE HEADER
/*void Party::recieveOffer(const Agent &agent){
    
    offers.append(agent)
    
    if(state == waiting)
        state = collectingOffers
    
}
*/
