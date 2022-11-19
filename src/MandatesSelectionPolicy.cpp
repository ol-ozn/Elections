#include "SelectionPolicy.h"

//arguments: currAgent.partyId ,sim.getGraph()
//returns: Party
Party MandatesSelectionPolicy::select(int agentPartyId, int agentCoalitionId ,const Graph &graph)
{
   Party *candidate;
   int mostMandates = -1;
   for(int i = 0; i < graph.getNumVertices(); i++)
   {
        if(graph.getEdgeWeight(agentPartyId, i) > 0)
        {
            Party party = graph.getParty(i);
            if(isValidCandidate(party, agentCoalitionId) && party.getMandates() > mostMandates)
                *candidate = party;
        }
   }
   return *candidate;
}