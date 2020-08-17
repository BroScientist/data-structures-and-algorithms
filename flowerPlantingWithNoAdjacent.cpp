#include <vector>
#include <list>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        // construct adjacency lists
        // starting with the first garden, loop through all four types of flowers until a valid one is found
        // a flower type is valid if it does not appear in any of the adjacent gardens

        unordered_map<int, list<int>> graph;
        for (vector<int>& path : paths)
        {
            graph[path[0]].push_back(path[1]);
            graph[path[1]].push_back(path[0]);
        }
        vector<int> res(N, 4);
        unordered_map<int, int> flower; // garden -> flower type
        vector<int> types = {1, 2, 3, 4};
        for (auto& item : graph)
        {
            for (int& type : types)
            {
                bool canPlant = true;
                for (int& nei : item.second)
                {
                    if (flower.find(nei) != flower.end() && flower[nei] == type)
                    {
                        canPlant = false;
                        break;
                    }
                }
                if (canPlant)
                {
                    flower[item.first] = type;
                    break;
                }
            }
        }

        // populate the res array with map elements
        for (auto& item : flower)
            res[item.first-1] = item.second;
        
        return res;
    }
};