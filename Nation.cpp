// Copyright (c) 2016 Roger Dubbs

#include "Nation.h"
#include "State.h"
#include <cassert>
#include <fstream>
#include <boost/range/adaptors.hpp>
#include <boost/range/numeric.hpp>

/**
 * The constitutionally dictated minimum of the number of persons represented by each representative.
 */
static const int minimumPersonsPerRepresentative = 30000;

Nation::Nation(std::vector<State>& states)
    :m_states{states}
{
}

const std::vector<State>& Nation::states() const
{
    return m_states;
}

unsigned int maxRepresentatives(const Nation& nation)
{
    unsigned long total = totalPopulation(nation);
    assert(total<std::numeric_limits<int>::max());
    return static_cast<unsigned int>(total/minimumPersonsPerRepresentative);
}

Population totalPopulation(const Nation& nation)
{
    using namespace boost::adaptors;
    return boost::accumulate(nation.states() | transformed([](const State& state) { return state.population(); }), 0UL);
}

Nation readPopulations(std::string filename)
{
    std::vector<State> result;
    std::ifstream in(filename);
    std::string line;
    //skip the header
    std::getline(in, line);
    while (std::getline(in, line)) {
        auto commaPosition = line.find(',');
        if (commaPosition!=std::string::npos) {
            std::string name(line, 0, commaPosition);
            unsigned long population = std::strtoul(&line[commaPosition+1], nullptr, 0);

            result.emplace_back(name, population);
        }
    }
    return Nation(result);
}