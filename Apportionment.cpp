// Copyright (c) 2016 Roger Dubbs

#include "Apportionment.h"

#include <cmath>
#include <queue>

#include "State.h"
#include "Nation.h"

/**
 * Track the number of representatives and priority for new representatives for a state.
 */
struct StateRepresentativeData {
    /**
     * Constructs the state data for the state given.
     * @param state The state this data is tracking
     */
    explicit StateRepresentativeData(const State& s)
        :state{&s},
         priority{s.population()/sqrt(2)},
         representativeCount{0}
    {
    }

    /**
     * Compares two StateData object by priority.
     * @param other The other state to compare against.
     * @return true if the priority of the state represented by this object is less than that represented by the other object.
     */
    bool operator<(const StateRepresentativeData& other) const
    {
        return priority<other.priority;
    }

    /**
     * Adds a representative to this state and adjusts its priority accordingly.
     */
    void addRepresentative()
    {
        double n = ++representativeCount;
        priority *= sqrt(n/(n+2));
    }

    const State* state;
    double priority;
    int representativeCount;
};

std::vector<const State*> representativeOrder(const Nation& nation)
{
    std::vector<const State*> result;

    // Create a priority queue and allocate one representative per state - the minimum.
    std::priority_queue<StateRepresentativeData> priorities;
    const std::vector<State>& states = nation.states();
    for (const State& state : states) {
        result.push_back(&state);
        priorities.emplace(state);
    }

    unsigned int maxReps = maxRepresentatives(nation);
    for (unsigned long i = states.size(); i<maxReps; i++) {
        StateRepresentativeData data = priorities.top();
        priorities.pop();
        result.push_back(data.state);
        data.addRepresentative();
        priorities.push(data);
    }
    return result;
}
