#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int> freq;
        int maxFreq = 0;
        for (int& n: nums)
        {
            freq[n]++;
            if (freq[n] > maxFreq)
                maxFreq = freq[n];
        }
        if (maxFreq == 1)
            return 1;
        
        vector<int> elems;
        for (auto& item: freq)
            if (item.second == maxFreq)
                elems.push_back(item.first);
        
        unordered_map<int,int> firstOccur, lastOccur;
        for (int i = 0; i < nums.size(); i++)
            if (firstOccur.find(nums[i]) == firstOccur.end())
                firstOccur[nums[i]] = i;
            
        for (int i = 0; i < nums.size(); i++)
            lastOccur[nums[i]] = i;
        
        int minLen = INT_MAX;
        for (int& n: elems)
        {
            int len = lastOccur[n] - firstOccur[n] + 1;
            if (len < minLen)
                minLen = len;
        }
        
        return minLen;
        
    }
};

int main() {

    return 0;
}