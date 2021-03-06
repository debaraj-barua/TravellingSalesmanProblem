#ifndef WORLD_HPP
#define WORLD_HPP

#include <string>
#include <vector>
using namespace std;

class World
{
    public:
        World(string filename);
        ~World();
        float getCycleLength(vector<int> cycle);
        int getNumCities();
        void cyclePlot(vector<int> cycle);
        void saveCyclePlot(vector<int> cycle, string filename);
        pair<float,float> get_coordinates(int city_index);
        string get_City(int city_index);

    private:
        void readCitiesFromFile(string filename);
        vector<string> cityNames;
        vector<pair<float,float>> coordinates;
        int numCities;
};
#endif
