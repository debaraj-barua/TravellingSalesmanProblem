#include <iostream>
#include <vector>
#include <algorithm> // contains std::random_shuffle to initialize a cycle
#include <agent.hpp>
#include <world.hpp>
#include <string>
#include <chrono>
#include <utility>
#include <time.h>

using namespace std;
using namespace std::chrono;

int main(int argc, char* argv[]) {
	std::srand(time(0));

    World myWorld = World("./input/49_cities.txt");
    cout << "number of cities: " << myWorld.getNumCities() << endl;

    int opt=0, cont=1;
    vector<int> cycle;

    //vector<vector<int>> cycle_simple_loop;
    //vector<vector<int>> cycle_steepest_loop;
    //int min_loop=0;

	high_resolution_clock::time_point t1 ;
	high_resolution_clock::time_point t2;
	auto execution_time= duration_cast<microseconds>( t2 - t1 ).count();

    while(cont==1)
    {
    	Agent current_agent=Agent(&myWorld);
    	cout<<"\n``````````````````````````````````````````````````````````````\n";
		cout<<"\t MENU\t\n";
		cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		cout<<"\n Select search algorithm: ";
		cout<<"\n 1) Simple Hill Climb";
		cout<<"\n 2) Steepest Ascent Hill Climb";
		/*
		cout<<"\n 3) Random Restart Simple Hill Climb";
		cout<<"\n 4) Random Restart Steepest Ascent Hill Climb";
		cout<<"\n``````````````````````````````````````````````````````````````\n";
		*/
		cin>>opt;

		switch (opt)
		{
		case 1:
				//Simple Hill Climb

				t1 = high_resolution_clock::now();						 //record start time
				cycle=current_agent.simpleHillClimb();					 //call function
				t2 = high_resolution_clock::now(); 						 //record end time

				execution_time = duration_cast<microseconds>( t2 - t1 ).count();

				cout<<"\n";
				cout<<"\n Performance Metrics:: ";
				cout<<"\n--------------------------";
				cout<<"\n FINAL Distance::: "<<current_agent.minimum_distance;
				cout<< " \n Number of Iterations: "<<current_agent.number_of_iterations;
				cout<<"\n Execution Time: "<<execution_time;
				cout<<"\n Press Enter to view plot";
				cin.ignore();
				cin.ignore();
				myWorld.cyclePlot(cycle);

				break;
		case 2:

				//Steepest Ascend Hill Climb

				t1 = high_resolution_clock::now(); 				//record start time
				cycle=current_agent.steepestAscendHillClimb();  //call function
				t2 = high_resolution_clock::now();				//record end time

				execution_time = duration_cast<microseconds>( t2 - t1 ).count();

				cout<<"\n";
				cout<<"\n Performance Matrix:: ";
				cout<<"\n--------------------------";
				cout<<"\n FINAL Distance::: "<<current_agent.minimum_distance ;
				cout<< " \n Number of Iterations: "<<current_agent.number_of_iterations;
				cout<<"\n Execution Time: "<<execution_time;
				cout<<"\n Press Enter to view plot";
				cin.ignore();
				cin.ignore();
				myWorld.cyclePlot(cycle);


				break;
		/*
		case 3:
				//Random Restart Simple Hill Climb
				int simple_loop;
				int simple_distance[20];
				int simple_iter[20];
				float execution_time_simple_loop[20];
				min_loop=0;

				cout<<"\n Enter number of loops: \n";
				cin>>simple_loop;

				for (int i=0; i<simple_loop;i++)
				{
					Agent current_agent_simple_loop=Agent(&myWorld);
					t1 = high_resolution_clock::now();

					cycle_simple_loop[i]=current_agent_simple_loop.simpleHillClimb();

					t2 = high_resolution_clock::now();

					execution_time_simple_loop[i] = duration_cast<microseconds>( t2 - t1 ).count();

					simple_distance[i]=current_agent_simple_loop.minimum_distance;
					simple_iter[i]=current_agent_simple_loop.number_of_iterations;
					if (simple_distance[i]<simple_distance[min_loop])
					{
						min_loop=i;
					}

				}

				cout<<"\n";
				cout<<"\n Performance Metrics:: ";
				cout<<"\n--------------------------";
				cout<<"\n FINAL Distance::: "<<simple_distance[min_loop];
				cout<< " \n Number of Iterations: "<<simple_iter[min_loop];
				cout<<"\n Execution Time: "<<execution_time_simple_loop[min_loop];
				cout<<"\n Press Enter to view plot";
				cin.ignore();
				cin.ignore();
				myWorld.cyclePlot(cycle_simple_loop[min_loop]);


				break;

		case 4:
				//Random Restart Steepest Ascent Hill Climb
				int steepest_loop;
				int steepest_distance[20];
				int steepest_iter[20];

				float execution_time_steepest_loop[20];
				min_loop=0;

				cout<<"\n Enter number of loops: \n";
				cin>>steepest_loop;

				for (int i=0; i<steepest_loop;i++)
				{
					Agent current_agent_steepest_loop=Agent(&myWorld);
					t1 = high_resolution_clock::now();

					cycle_steepest_loop[i]=current_agent_steepest_loop.simpleHillClimb();

					t2 = high_resolution_clock::now();

					execution_time_steepest_loop[i] = duration_cast<microseconds>( t2 - t1 ).count();

					steepest_distance[i]=current_agent_steepest_loop.minimum_distance;
					steepest_iter[i]=current_agent_steepest_loop.number_of_iterations;
					if (steepest_distance[i]<steepest_distance[min_loop])
					{
						min_loop=i;
					}

				}

				cout<<"\n";
				cout<<"\n Performance Metrics:: ";
				cout<<"\n--------------------------";
				cout<<"\n FINAL Distance::: "<<steepest_distance[min_loop];
				cout<< " \n Number of Iterations: "<<steepest_iter[min_loop];
				cout<<"\n Execution Time: "<<execution_time_simple_loop[min_loop];
				cout<<"\n Press Enter to view plot";
				cin.ignore();
				cin.ignore();
				myWorld.cyclePlot(cycle_steepest_loop[min_loop]);
				break;
		 */

		default: cout<<"\n Wrong input. Please try again.";
				break;
		}

		cout<<"\n Press 1 to continue... \n";
		cin>>cont;
    }


    cout<<"\nExiting";
    return 0;
}
