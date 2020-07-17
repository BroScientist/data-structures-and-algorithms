#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for (int i = 0; i < A.size(); i++)
        {
            int start = 0, end = A[i].size() - 1;
            while (start < end)
            {
                int tmp = A[i][end];
                A[i][end] = A[i][start];
                A[i][start] = tmp;
                start++;
                end--;
            }
        }
        for (int i = 0; i < A.size(); i++)
            for (int j = 0; j < A[0].size(); j++)
                A[i][j] = A[i][j] == 1 ? 0 : 1;
        return A;
    }
};

int main() {

    return 0;
}