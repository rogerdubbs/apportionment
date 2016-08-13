// Copyright (c) 2016 Roger Dubbs

#pragma once

#include "Population.h"
#include "Name.h"

/**
 * Represents a state within a nation, such as Texas is a state of the United States.
 */
class State {
public:
    /**
     * Constructs a state with the name and population given.
     * @param name The name of the state.
     * @param population The population of the state.
     */
    State(const Name& name, Population population);

    /**
     * @return the name of the state.
     */
    Name name() const;

    /**
     * @return the population of the state
     */
    Population population() const;
private:
    Name m_name;
    Population m_population;
};
