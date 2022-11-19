#include "SelectionPolicy.h"
#include <iostream> //Remove

//arguments: currAgent.partyId ,sim.getGraph()
//returns: Party
Party *MandatesSelectionPolicy::select(int agentPartyId, int agentCoalitionId ,const Graph &graph)
{
   Party *candidate = nullptr;
   int mostMandates = -1;
   for(int i = 0; i < graph.getNumVertices(); i++)
   {
        if(graph.getEdgeWeight(agentPartyId, i) > 0)
        {
            Party party = graph.getParty(i);
            if(isValidCandidate(party, agentCoalitionId) && party.getMandates() > mostMandates)
            {
                *candidate = party;
                mostMandates = party.getMandates();
            }
        }
   }
   return candidate;
}

//MIGHT NOT CALL PAERNT FUNCTION
bool MandatesSelectionPolicy::isValidCandidate(Party &party, int coalitionId)
{
    std::cout << "MandatesSelectionPolicy::isValidCandidate" << std::endl; //REMOVE
}