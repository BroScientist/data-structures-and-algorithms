#include <vector>
#include <queue>
#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> hashtable;
        priority_queue<int, vector<int>, greater<int>> heap;
        
        for (int& n : nums)
            hashtable[n]++;
        
        // for item in hashtable, if count of num is greater than the Kth most frequent in heap (min heap's top)
        // replace min heap pop, then push num
        // item.first is num, second is frequency
        for (auto& item : hashtable)
        {
            heap.push(item.second);
            if (heap.size() > k)
                heap.pop();
        }
        vector<int> res;

        while (!heap.empty())
        {
            auto it = hashtable.begin();
            while(it != hashtable.end())
            {
                // Check if value of this entry matches with given value
                if(it->second == heap.top())
                {
                    // found, push to res
                    res.push_back(it->first);
                    hashtable.erase(it);
                    break;
                }
                it++;
            }
            heap.pop();
        }
        return res;
    }
};