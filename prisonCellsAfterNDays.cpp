#include <iostream>
#include <vector>

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        // the pattern starts repeating after 14 steps (according to user rajatag03)
        if (N > 14)
            N = N % 14 == 0 ? 14 : N % 14;
        vector<int> prev = cells;
        // set first and last cell to zero
        cells[0] = 0;
        cells[cells.size() - 1] = 0;
        for (int j = 0; j < N; j++)
        {
            for (int i = 1; i < cells.size() - 1; i++)
            {
                if (prev[i-1] == prev[i+1])
                    cells[i] = 1;
                else
                    cells[i] = 0;
            }
            prev = cells;
        }
        return cells;
    }
};

