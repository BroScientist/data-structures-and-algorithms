#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> copy = nums;
        for (int i = 0; i < copy.size(); i++)
            nums[(i+k)%copy.size()] = copy[i];
    }
};

int main() {

    return 0;
}