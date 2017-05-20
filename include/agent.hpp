#ifndef AGENT_HPP
#define AGENT_HPP

#include <vector>
#include "world.hpp"

using namespace std;

class Agent {
    public:
        Agent(World* worldPtr);
        ~Agent();

        vector<int> simpleHillClimb();
        vector<int> steepestAscendHillClimb();
        float get_distance(vector<int>);
        vector<vector<int>> get_successors(vector<int>);

    private:
        World* worldPtr;
        vector<int> currentCycle;
};
#endif
