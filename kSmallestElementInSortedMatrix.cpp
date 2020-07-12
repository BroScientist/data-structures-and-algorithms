#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // a better solution would be to search the 1st row and 1st col, then increment row and col
        // use max heap to maintain the K smallest elements
        priority_queue<int> heap;
        int count = 0;
        for (int row = 0; row < matrix.size(); row++)
        {
            for (int col = 0; col < matrix[0].size(); col++)
            {
                heap.push(matrix[row][col]);
                if (heap.size() > k)
                    heap.pop();
                count++;
                // if (count >= k + matrix[0].size())
                // {
                //     cout << "found early" << endl;
                //     return heap.top();
                // }
            }
        }
        return heap.top();
    }
};