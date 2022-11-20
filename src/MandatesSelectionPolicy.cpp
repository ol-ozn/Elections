#include "SelectionPolicy.h"
#include <iostream> //Remove

//arguments: currAgent.partyId ,sim.getGraph()
//returns: Party
int MandatesSelectionPolicy::select(int agentPartyId, int agentCoalitionId ,const Graph &graph)
{
   Party *candidate = nullptr;
   int mostMandates = -1;
   int candidateId = -1;
   for(int i = 0; i < graph.getNumVertices(); i++)
   {
        if(graph.getEdgeWeight(agentPartyId, i) > 0)
        {
            Party party = graph.getParty(i);
            if(party.getState() != Joined && !party.coalitionOffered(agentCoalitionId) && party.getMandates() > mostMandates)
            {
                *candidate = party;
                mostMandates = party.getMandates();
                candidateId = i;
            }
        }
   }
   return candidateId;
}
