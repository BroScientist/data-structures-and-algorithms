#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        map<int, int> hashtable;
        for (int i = 1; i < nums.size() + 1; i++)
            hashtable[i] = 0;
        for (int& n : nums)
            hashtable[n]++;
        for (auto& item : hashtable)
        {
            if (item.second == 0)
                res.push_back(item.first);
        }
        return res;
    }
};

int main() {

    return 0;
}