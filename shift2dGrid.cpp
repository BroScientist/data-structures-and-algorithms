class Solution {
public:

    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int rows = grid.size(), cols = grid[0].size();
        vector<int> flattened(rows * cols);
        int index = 0;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                flattened[index++] = grid[i][j];
        vector<int> copy = flattened;
        for (int i = 0; i < copy.size(); i++)
            flattened[(i+k)%copy.size()] = copy[i];
        index = 0;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                grid[i][j] = flattened[index++];
        return grid;
    }
};