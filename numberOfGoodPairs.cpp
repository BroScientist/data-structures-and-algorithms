#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        map<int, int> hashtable;
        int count = 0;
        for (int& n : nums)
        {
            // if n is already in, it creates a good pair
            if (hashtable.find(n) != hashtable.end())
                count += hashtable[n];
            hashtable[n]++;
        }
        // for (auto& item : hashtable)
        //     cout << item.first << " " << item.second << endl;
        return count;
    }
};