#include <vector>
#include <list>
#include <map>
using namespace std;

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        map<pair<int,int>, list<pair<int,int>>> graph;
        for (int row = 0; row < grid.size(); row++)
        {
            for (int col = 0; col < grid[0].size(); col++)
            {
                if (grid[row][col] == 1)
                {
                    for (int i = row + 1; i < grid.size(); i++)
                    {
                        if (grid[i][col] == 1)
                        {
                            graph[make_pair(row, col)].push_back(make_pair(i, col));
                            graph[make_pair(i, col)].push_back(make_pair(row, col));
                        }
                    }
                    for (int j = col + 1; j < grid[0].size(); j++)
                    {
                        if (grid[row][j] == 1)
                        {
                            graph[make_pair(row, col)].push_back(make_pair(row, j));
                            graph[make_pair(row, j)].push_back(make_pair(row, col));
                        }
                    }
                }
                
            }
        }
        return graph.size();
    }
};