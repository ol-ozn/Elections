#pragma once
#include "Graph.h"
#include "Party.h"

class SelectionPolicy {
    public:
        virtual Party *select(int agentPartyId, int agentCoalitionId, const Graph &graph) = 0;
 };

class MandatesSelectionPolicy: public SelectionPolicy{
    public:
        Party *select(int agentPartyId, int agentCoalitionId, const Graph &graph);

 };

class EdgeWeightSelectionPolicy: public SelectionPolicy{
    public:
        Party *select(int agentPartyId, int agentCoalitionId, const Graph &graph);
 };