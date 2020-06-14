#include <iostream>
#include <vector>

using namespace std;

vector<int> shuffle(vector<int>& nums, int n) {
    vector<int> result(nums.size());
    int index = 0;
    for (int i = 0; i < n; i++) 
    {
        result[index++] = nums[i];
        result[index++] = nums[i+n];
    }
    for (int& n : result) cout << n << " ";
    return result;
}

int main() {
    vector<int> nums{2,5,1,3,4,7};
    shuffle(nums, 3);
    return 0;
}