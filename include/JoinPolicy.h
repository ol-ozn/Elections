#pragma once

class JoinPolicy {
    public:
        virtual void join() = 0;
};

class MandatesJoinPolicy : public JoinPolicy {
    public:
        void join();
};

class LastOfferJoinPolicy : public JoinPolicy {
    public:
        void join();
};