#include <iostream>
#include <vector>
#include <algorithm> // contains std::random_shuffle to initialize a cycle
#include <agent.hpp>
#include <world.hpp>
#include <string>
using namespace std;


int main(int argc, char* argv[]) {

    // Simple usage example
    World myWorld = World("./input/49_cities.txt");
    cout << "number of cities: " << myWorld.getNumCities() << endl;
    vector<int> cycle;
    Agent current_agent=Agent(&myWorld);

    /*
    // create random cycle
    vector<int> cycle;
    for (int i = 0; i < myWorld.getNumCities(); i++) cycle.push_back(i);
    random_shuffle(cycle.begin(), cycle.end());

    myWorld.saveCyclePlot(cycle, "./test.png");
	*/

    int opt=0, cont=1;
    string name;
    std::string file_name;

    while(cont==1)
    {
    	cout<<"\t MENU\t\n";
		cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		cout<<"\n Select search algorithm: ";
		cout<<"\n 1) Simple Hill Climb";
		cout<<"\n 2) Steepest Ascent Hill Climb\n";
		cin>>opt;

		switch (opt)
		{
		case 1:
				//Simple Hill Climb
					name="";
					file_name="";
					cycle=current_agent.simpleHillClimb();
					myWorld.cyclePlot(cycle);
					//cout<<"\n Saving to file \"Simple_hill_climb_*\"";
					//cout<<"\nPlease enter file name ending.. \n";
					//cin>>name;
					//file_name="./Simple_hill_climb_"+name;
			    	//cout<<"\nSaving.. "<<file_name;
					///myWorld.saveCyclePlot(cycle, file_name);


				break;
		case 2:

		    	//Steepest Ascend Hill Climb
					name="";
					file_name="";
					cycle=current_agent.steepestAscendHillClimb();
					myWorld.cyclePlot(cycle);
					/*
					cout<<"\n Saving to file \"Steepest_hill_climb_*\"";
					cout<<"\nPlease enter file name ending.. \n";
					cin>>name;
					file_name="./Steepest_hill_climb_"+name;
					cout<<"\nSaving.. "<<file_name;
					//myWorld.saveCyclePlot(cycle, file_name);
					*/

				break;
		default: cout<<"\n Wrong input. Please try again.";
				break;
		}
		cout<<"\n Press 1 to continue... \n";
		cin>>cont;
    }

   //TO DO
    //Perform hill climbing here
    //Evaluate runtimes and results
    cout<<"\nExitting";
    return 0;
}
