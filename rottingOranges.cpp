#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        bool changed = false;
        queue<vector<int>> queue;
        int fresh = 0;
        for (int i = 0; i < grid.size(); i++)
        {            
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 2)
                    queue.push({i, j});
                else if (grid[i][j] == 1)
                    fresh++;
            }
        }
        if (fresh == 0)
            return 0;
        if (queue.empty())
            return -1;
        
        int minutes = 0;
        
        while (!queue.empty())
        {
            int count = queue.size();
            if (count != 0)
                minutes++;
            else
                break;
            while (count != 0)
            {
                vector<int> curr = queue.front();
                int row = curr[0], col = curr[1];
                queue.pop();
                // up
                if (row - 1 >= 0 && grid[row - 1][col] == 1)
                {
                    fresh--;
                    grid[row - 1][col] = 2;
                    queue.push({row - 1, col});
                    
                }
                // down
                if (row + 1 < grid.size() && grid[row + 1][col] == 1)
                {
                    fresh--;
                    grid[row + 1][col] = 2; 
                    queue.push({row + 1, col});   
                }
                // left
                if (col - 1 >= 0 && grid[row][col - 1] == 1)
                {
                    fresh--;
                    grid[row][col - 1] = 2;
                    queue.push({row, col - 1});
                }
                // right
                if (col + 1 < grid[0].size() && grid[row][col + 1] == 1)
                {

                    fresh--;
                    grid[row][col + 1] = 2;
                    queue.push({row, col + 1});
                    
                }
                count--;
                if (fresh <= 0)
                    return minutes;
            }
        }
        if (fresh != 0)
            return -1;
        return minutes;
    }
};


int main() {

    return 0;
}