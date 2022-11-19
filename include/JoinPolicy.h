#pragma once
#include "Agent.h"
#include <vector>

using std::vector;

class JoinPolicy {
    public:
        virtual Agent join(const vector<Agent> &offers) = 0;
};

class MandatesJoinPolicy : public JoinPolicy {
    public:
        virtual Agent join(const vector<Agent> &offers);
};

class LastOfferJoinPolicy : public JoinPolicy {
    public:
        virtual Agent join(const vector<Agent> &offers);
};