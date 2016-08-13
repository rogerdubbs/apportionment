// Copyright (c) 2016 Roger Dubbs
#include <iostream>
#include <boost/range/numeric.hpp>

#include "Apportionment.h"
#include "State.h"
#include "Nation.h"

/**
 * Program to compute the priority list for representatives given a file with state,population pairs.  The result
 * is written to stdout.
 *
 * @param argc The number of arguments - should be 2.
 * @param argv The vector of arguments.  The program name should be arg[0] and the file name of populations should be arg[1]
 * @return 0 if successful, 1 if there is an error.
 */
int main(int argc, char** argv)
{
    if (argc<2) {
        std::cerr << "Usage: apportionment populationFile" << std::endl;
        std::cerr << "where populationFile is a comma separated file with header" << std::endl;
        std::cerr << "State,Population" << std::endl;
        return 1;
    }
    std::string fileName{argv[1]};
    Nation states = readPopulations(fileName);
    std::vector<const State*> allocations = representativeOrder(states);

    std::cout << "Index, State" << std::endl;
    int sequenceNumber = 0;
    for (const auto& state: allocations) {
        std::cout << ++sequenceNumber << "," << state->name() << std::endl;
    }
    return 0;
}
