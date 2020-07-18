#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // transpose + reverse rows
        int n = matrix.size();
        vector<vector<int>> visited;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                int tmp = matrix[j][i];
                matrix[j][i] = matrix[i][j];
                matrix[i][j] = tmp;
            }
        }
        for (int i = 0; i < n; i++)
        {
            int start = 0, end = n - 1;
            while (start < end)
            {
                int tmp = matrix[i][end];
                matrix[i][end] = matrix[i][start];
                matrix[i][start] = tmp;
                start++;
                end--;
            }
        }
    }
};

int main() {

    return 0;
}