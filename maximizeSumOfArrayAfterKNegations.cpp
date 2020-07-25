#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        int sum = accumulate(begin(A), end(A), 0);
        sort(begin(A), end(A));
        int index = 0, minPositive = INT_MAX;
        for (int i = 0; i < K; i++)
        {
            // priority: negative numbers, zero, smallest positive number
            if (A[index] == 0)
                break;
            if (A[index] < 0)
            {
                sum += -A[index] * 2;
                minPositive = min(minPositive, abs(A[index]));
                index++;
            }
            else
            {
                // else, we've found the smallest positive number
                // we continously use this number because this is now the best we can do for each remaining step
                minPositive = min(minPositive, abs(A[index]));
                if ((K - i) % 2 == 0)
                    return sum;
                else
                    return sum - minPositive * 2;
                
            }
        }
        return sum;
    }
};

int main() {

    return 0;
}