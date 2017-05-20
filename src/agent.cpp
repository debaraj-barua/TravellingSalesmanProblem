/*
 * Daniel Vázquez
 * Aritificial Intelligence for Robotics
 * SS 2016
 * Assignment 7
 *
 * agent.cpp
 * */
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <agent.hpp>

/*
Agent::Agent(World* worldPtr) : worldPtr(worldPtr)
{}
*/
Agent::Agent(World* worldPtr)
{
	this->worldPtr=worldPtr;
	std::srand(time(0));
}

Agent::~Agent()
{}

vector<int> Agent::simpleHillClimb()
{
    //TO DO
	World myWorld=*worldPtr;
	vector<int> cycle;
	vector<vector<int>> successors;
	float current_dist=0;
	bool flag=true;

	for (int i = 0; i < myWorld.getNumCities(); i++) cycle.push_back(i);
	random_shuffle(cycle.begin(), cycle.end());
	currentCycle=cycle;

	while (flag==true)
	{
		successors=get_successors(currentCycle);
		current_dist=get_distance(currentCycle);
		int i=0;
		for (i=0;i<successors.size();i++)
		{
			float successor_dist=get_distance(successors[i]);
			if (successor_dist<current_dist)
			{
				currentCycle=successors[i];
				break;
			}
		}
		if (i==successors.size())
		{
			flag=false;
		}
	}

	cout<<"\n FINAL Distance::: "<<get_distance(currentCycle);
	return currentCycle;

}
vector<int> Agent::steepestAscendHillClimb()
{
    //TO DO
	World myWorld=*worldPtr;
	vector<int> cycle;
	vector<vector<int>> successors;
	float current_dist=0, min_dist=0;
	bool flag=true;

	for (int i = 0; i < myWorld.getNumCities(); i++) cycle.push_back(i);
	random_shuffle(cycle.begin(), cycle.end());
	currentCycle=cycle;

	while (flag==true)
	{
		successors=get_successors(currentCycle);
		current_dist=get_distance(currentCycle);
		int i=0;
		for (i=0;i<successors.size();i++)
		{
			float successor_dist=get_distance(successors[i]);
			if (successor_dist<current_dist)
			{
				currentCycle=successors[i];
				current_dist=get_distance(currentCycle);
			}
		}
		if (i==successors.size())
		{
			flag=false;
		}
	}

	cout<<"\n FINAL Distance::: "<<get_distance(currentCycle);
	return currentCycle;
}


float Agent::get_distance(vector<int> cycle)
{
	float dist=0;

	for (int i=0; i+1<cycle.size();i++)
	{
			dist+= sqrt(pow((worldPtr->get_coordinates(cycle[i]).first-worldPtr->get_coordinates(cycle[i+1]).first),2) +pow((worldPtr->get_coordinates(cycle[i]).second-worldPtr->get_coordinates(cycle[i+1]).second),2));
	}

	dist+=sqrt(pow((worldPtr->get_coordinates(cycle[cycle.size()-1]).first-worldPtr->get_coordinates(cycle[0]).first),2) +pow((worldPtr->get_coordinates(cycle[cycle.size()-1]).second-worldPtr->get_coordinates(cycle[0]).second),2));
	return dist;
}
vector<vector<int>> Agent::get_successors(vector<int> cycle)
{
	vector<vector<int>> successors;

	for (int i=0; i<cycle.size();i++)
	{
		for (int j=i+1;j<cycle.size();j++)
		{
			vector<int> temp=cycle;
			int swap_var=cycle[i];
			cycle[i]=cycle[j];
			cycle[j]=swap_var;
			successors.push_back(temp);
		}
	}

	return successors;
}
