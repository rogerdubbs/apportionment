// Copyright (c) 2016 Roger Dubbs

#pragma once

#include <vector>
#include <string>
#include "Population.h"

class State;

/**
 * A nation consisting of a number of states.  This concept is currently modeled on the United States of America.
 */
class Nation {
public:
    explicit Nation(std::vector<State>& states);

    /**
     * @return the list of all the states of the nation.
     */
    const std::vector<State>& states() const;

private:
    std::vector<State> m_states;
};

/**
 * Compute the maximum number of representatives for the states given - one per 30000 total population.
 * @param states The states to compute the representation for.
 * @return the maximum number of representatives.
 */
unsigned int maxRepresentatives(const Nation& nation);

/**
 * Load a nation from the named CSV file.
 * The CSV file must contain State,Population
 *
 * @param filename The name of the file to read the data from
 * @return A list of all the states in the CSV File.
 */
Nation readPopulations(std::string filename);

/**
 * Returns the total population of the nation passed.
 * @param nation The nation to compute the population of.
 * @return The population of the nation.
 */
Population totalPopulation(const Nation& nation);
