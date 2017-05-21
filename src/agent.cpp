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
#include <chrono>
#include <utility>
#include <time.h>

using namespace std;
using namespace std::chrono;

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

	World myWorld=*worldPtr;
	vector<int> cycle;
	vector<vector<int>> successors;
	float current_dist=0;
	bool flag=true;

	/*Shuffle initial state of city*/
	for (int i = 0; i < myWorld.getNumCities(); i++) cycle.push_back(i);
	random_shuffle(cycle.begin(), cycle.end());
	currentCycle=cycle;
	cout<<"\n INITIAL random Distance::: "<<get_distance(currentCycle);

	int k=0; //to store number of iteration

	/*Loop until there are no successors with lesser total distance*/
	while (flag==true)
	{
		k++; 											//increment iteration
		successors=get_successors(currentCycle);
		current_dist=get_distance(currentCycle);
		int i=0;

		//Loop for all successors till the first with lesser total distance
		for (i=0;i<successors.size();i++)
		{
			float successor_dist=get_distance(successors[i]);

			//if successor distance is less then current, make this current and break loop
			if (successor_dist<current_dist)
			{
				currentCycle=successors[i];
				break;
			}
		}

		//if all successors have been searched, and no better result found,
		//break and return current state as result.
		if (i==successors.size())
		{
			flag=false;
		}
	}

	number_of_iterations=k;
	minimum_distance=get_distance(currentCycle);

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

	/*Shuffle initial state of city*/
	for (int i = 0; i < myWorld.getNumCities(); i++) cycle.push_back(i);
	random_shuffle(cycle.begin(), cycle.end());
	currentCycle=cycle;
	cout<<"\n INITIAL random Distance::: "<<get_distance(currentCycle);


	int k=0;//to store number of iteration

	/*Loop until there are no successors with lesser total distance*/
	while (flag==true)
	{	k++;												//increment iteration
		flag=false;

		successors=get_successors(currentCycle);
		current_dist=get_distance(currentCycle);
		int i=0;

		//Loop for all successors to get successor with minimum total distance
		for (i=0;i<successors.size();i++)
		{
			current_dist=get_distance(currentCycle);
			float successor_dist=get_distance(successors[i]);

			//if any valid successor is found, set flag as true to continue loop
			if (successor_dist<current_dist)
			{
				currentCycle=successors[i];
				current_dist=get_distance(currentCycle);
				flag=true;
			}
		}

	}

	number_of_iterations=k;
	minimum_distance=get_distance(currentCycle);

	return currentCycle;
}


/*
 * Since we are concerned with comparison of distances only, we have considered
 * Cartesian distances as actual distance between two cities
 *
 * */

float Agent::get_distance(vector<int> cycle)
{
	float dist=0;

	//Add distances from first city to last sequentially
	for (int i=0; i+1<cycle.size();i++)
	{
			dist+= sqrt(
					 pow((worldPtr->get_coordinates(cycle[i]).first-worldPtr->get_coordinates(cycle[i+1]).first),2)
					+pow((worldPtr->get_coordinates(cycle[i]).second-worldPtr->get_coordinates(cycle[i+1]).second),2)
					    );
	}

	//Finally, add distance between last and first city to complete the journey
	dist+=sqrt(
			 pow((worldPtr->get_coordinates(cycle[cycle.size()-1]).first-worldPtr->get_coordinates(cycle[0]).first),2)
			+pow((worldPtr->get_coordinates(cycle[cycle.size()-1]).second-worldPtr->get_coordinates(cycle[0]).second),2)
			  );

	return dist;
}

/*
 * This function returns a vector of successors, by permutation of all possible sequences of the cities
 * */
vector<vector<int>> Agent::get_successors(vector<int> cycle)
{
	vector<vector<int>> successors;

	for (int i=0; i<cycle.size();i++)
	{
		for (int j=i+1;j<cycle.size();j++)
		{
			vector<int> temp=cycle;
			int swap_var=temp[i];
			temp[i]=temp[j];
			temp[j]=swap_var;
			successors.push_back(temp);
		}
	}

	return successors;
}
