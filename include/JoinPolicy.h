#pragma once
#include "Agent.h"
#include <vector>

using std::vector;

class Graph;

class JoinPolicy {
    public:
        virtual int join(const vector<Agent> &offers, const Graph &graph) = 0;
};

class MandatesJoinPolicy : public JoinPolicy {
    public:
        virtual int join(const vector<Agent> &offers, const Graph &graph);
};

class LastOfferJoinPolicy : public JoinPolicy {
    public:
        virtual int join(const vector<Agent> &offers, const Graph &graph);
};