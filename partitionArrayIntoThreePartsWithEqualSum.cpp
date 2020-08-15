#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum = accumulate(begin(A), end(A), 0);
        if (sum % 3 != 0)
            return false;
        int target = sum / 3, currSum = 0, parts = 0;
        for (int i = 0; i < A.size(); i++)
        {
            currSum += A[i];
            if (currSum == target)
            {
                parts++;
                currSum = 0;
            }
            if (parts == 2 && i != A.size() - 1)
            {
                for (int j = i + 1; j < A.size(); j++)
                {
                    currSum += A[j];
                }
                if (currSum == target)
                    return true;
            }

        }
        return false;
    }
};

/*
approach one: accumulate sum until it reaches target, reset to zero, increment count, continue
what 
*/