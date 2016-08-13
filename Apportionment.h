// Copyright (c) 2016 Roger Dubbs

#pragma once

#include <vector>

class Nation;

class State;

/**
 * Returns the representatives due for each state in priority order.  The number of entries in the vector will be the
 * maximum possible number of representatives due to the constitutional restriction of a minimum of one representative
 * per 30,000, and at least one per state, as per this clause of the constitution:
 * "The number of Representatives shall not exceed one for every thirty Thousand, but each State shall have at Least one
 * Representative;"
 * @param nation The nation to apportion representatives for.
 * @return the representatives due for each state in priority order.  The pointers are to the states in Nation and thus
 * will be valid only as long as Nation is valid.
 */
std::vector<const State*> representativeOrder(const Nation& nation);
