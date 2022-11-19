#pragma once
#include "Graph.h"
#include "Party.h"

class SelectionPolicy {
    public:
        virtual Party *select(int agentPartyId, int agentCoalitionId, const Graph &graph) = 0;
        bool isValidCandidate(Party &party, int coalitionId);
 };

class MandatesSelectionPolicy: public SelectionPolicy{
    public:
        Party *select(int agentPartyId, int agentCoalitionId, const Graph &graph);
        bool isValidCandidate(Party &party, int coalitionId);

 };

class EdgeWeightSelectionPolicy: public SelectionPolicy{
    public:
        Party *select(int agentPartyId, int agentCoalitionId, const Graph &graph);
        bool isValidCandidate(Party &party, int coalitionId);
 };