#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Compare
{
public:
    bool operator() (pair<int,int> a, pair<int,int> b)
    {
        return (a.second < b.second);
    }
};

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> heap;
        unordered_map<int, int> freq;
        for (int& n : arr)
            freq[n]++;
        for (auto& item : freq)
            heap.push(make_pair(item.first, item.second));
        
        // removed = total number of elements we have removed
        // count = total number of distinct elements we have removed
        int half = arr.size() / 2, removed = 0, count = 0;
        while (removed < half)
        {
            removed += heap.top().second;
            count++;
            heap.pop();
        }
        
        return count;
    }
};
