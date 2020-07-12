#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        vector<int> res(A.size());
        int evenIndex = 0, oddIndex = 1;
        for (int& num : A)
        {
            if (num % 2 == 0)
            {
                res[evenIndex] = num;
                evenIndex += 2;
            }
            else
            {
                res[oddIndex] = num;
                oddIndex += 2;
            }
        }
        return res;
    }
};

int main() {

    return 0;
}