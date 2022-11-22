#include "SelectionPolicy.h"

int MandatesSelectionPolicy::select(int agentPartyId, int agentCoalitionId ,const Graph &graph)
{
   int mostMandates = -1;
   int candidateId = -1;
   for(int i = 0; i < graph.getNumVertices(); i++)
   {
        if(graph.getEdgeWeight(agentPartyId, i) > 0)
        {
            Party party = graph.getParty(i);
            if(party.getState() != Joined && !party.coalitionOffered(agentCoalitionId) && party.getMandates() > mostMandates)
            {
                mostMandates = party.getMandates();
                candidateId = i;
            }
        }
   }
   
   return candidateId;
}
