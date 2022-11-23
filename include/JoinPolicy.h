#pragma once
#include "Agent.h"
#include <vector>

using std::vector;

class Graph;

class JoinPolicy {
    public:
        virtual int join(const vector<Agent> &offers, const Graph &graph) = 0;
        virtual ~JoinPolicy() = default;
        virtual JoinPolicy *clone() = 0;
};

class MandatesJoinPolicy : public JoinPolicy {
    public:
        virtual int join(const vector<Agent> &offers, const Graph &graph);
        JoinPolicy *clone();
};

class LastOfferJoinPolicy : public JoinPolicy {
    public:
        virtual int join(const vector<Agent> &offers, const Graph &graph);
        JoinPolicy *clone();
};