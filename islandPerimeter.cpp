#include <iostream>
#include <vector>

using namespace std;

int islandPerimeter(vector<vector<int>>& grid) {
    // default perimeter of each land is 4
    // for each piece of land up, down, left or right of the current, minus one from perimeter
    int total_perimeter = 0;
    int curr = 4;
    for (int row = 0; row < grid.size(); row++)
    {
        for (int col = 0; col < grid[0].size(); col++)
        {
            if (grid[row][col] == 1)
            {
                // if current block is land, check how many neighboring lands it has
                if (row > 0 && grid[row-1][col] == 1) // up
                    curr--;
                if (row < grid.size() - 1 && grid[row+1][col] == 1) // down
                    curr--;
                if (col > 0 && grid[row][col-1] == 1) // left
                    curr--;
                if (col < grid[row].size() -1 && grid[row][col+1] == 1) // down
                    curr--;
                total_perimeter += curr;
                curr = 4;
            }
        }
    }
    // cout << total_perimeter << endl;
    return total_perimeter;
}

int main() {

    return 0;
}