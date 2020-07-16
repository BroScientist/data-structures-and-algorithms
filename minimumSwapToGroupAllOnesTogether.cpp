#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSwaps(vector<int>& data) {
        // the final result should be a window completely filled with all ones in the data array
        // therefore windowSize should be the number of one count
        int windowSize = count(begin(data), end(data), 1);
        
        // use a ones variable to track how many ones are in the current window
        int ones = 0;
        for (int i = 0; i < windowSize; i++)
        {
            if (data[i] == 1)
                ones++;
        }
        
        // zeros indicates how many swaps must be made
        int swaps = windowSize - ones;

        // loop over the array to find the optimal window
        // vector<int> res;
        int minSwaps = swaps;
        for (int i = windowSize; i < data.size(); i++)
        {
            if (data[i - windowSize] == 1)
                ones--;
            if (data[i] == 1)
                ones++;
            swaps = windowSize - ones;
            if (swaps < minSwaps)
                minSwaps = swaps;
        }
        return minSwaps;
    }
};

int main() {

    return 0;
}