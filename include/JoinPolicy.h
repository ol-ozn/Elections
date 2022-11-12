#pragma once

class JoinPolicy {
    public:
        virtual void join() = 0;
};

class MandatesJoinPolicy : public JoinPolicy {};

class LastOfferJoinPolicy : public JoinPolicy {};