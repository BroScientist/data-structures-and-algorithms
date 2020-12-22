class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        queue<vector<int>> q;
        int m = rooms.size();
        // the empty case got me bruh...
        if (m == 0)
            return;
        int n = rooms[0].size(), EMPTY = INT_MAX;
        
        // scan the input and push every gate into the queue
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (rooms[i][j] == 0)
                    q.push(vector<int>{i, j});
        
        // define directions for easy navigation
        vector<vector<int>> DIRECTIONS = 
        {
            {1, 0}, // up
            {-1, 0}, // down
            {0, 1}, // right
            {0, -1}, // left

        };
        
        while (!q.empty())
        {
            int row = q.front()[0], col = q.front()[1];
            q.pop();
            // loop over every direction and update distance if it is in grid & not an obstable & not visited
            for (vector<int>& direction: DIRECTIONS)
            {
                // direction[0] is x axis, 1 is y axis
                int newRow = row + direction[0];
                int newCol = col + direction[1];
                if (newRow < 0 || newRow >= m || newCol < 0 || newCol >= n || rooms[newRow][newCol] != EMPTY)
                    continue;
                rooms[newRow][newCol] = rooms[row][col] + 1;
                q.push(vector<int>{newRow, newCol});
            }
        }
    }
};