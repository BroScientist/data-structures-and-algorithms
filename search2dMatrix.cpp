#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int binarySearch(vector<vector<int>>& matrix, int& target)
    {
        int m = matrix.size(), n = matrix[0].size();
        int index = -1, low = 0, high = (m * n) - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            int col = mid % n;
            int row = mid / n;
            if (matrix[row][col] == target)
            {
                index = mid;
                break;
            }
            else if (matrix[row][col] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return index;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0)
            return false;
        return binarySearch(matrix, target) == -1 ? false : true;
        
    }
};

