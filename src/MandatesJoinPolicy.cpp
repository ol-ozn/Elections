#include "JoinPolicy.h"
#include "Graph.h"

//argument: const &Vector<Agent>
//returns: Agent

//argument: vector<int> partyId of offering agents, (copy/reference) dict<partyId,numMandates> paerties
//return chosen agent id
int MandatesJoinPolicy::join(const vector<Agent> &offers, const Graph &graph) 
{
    /* 
        //iterate over the vector, choose agent with maxiaml number of mandates 
        return chosen agent
    */
   //if the maximum has 2 parties with the number, then pick the first who offered
    Agent *chosenAgent;
    int mostMandates = -1;
    int candidateId = -1;
    for(Agent candidate : offers)
    {
        int currMandates = graph.getParty(candidate.getPartyId()).getMandates();
        if(currMandates > mostMandates)
        {
            // *chosenAgent = candidate; //FAILS HERE
            mostMandates = currMandates;
            candidateId = candidate.getId();
        }
    }

    return candidateId;
}