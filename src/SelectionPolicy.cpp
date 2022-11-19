#include "SelectionPolicy.h"

bool SelectionPolicy::isValidCandidate(Party &party, int coalitionId)
{
    return (party.getState() != Joined && !party.coalitionOffered(coalitionId));
}

