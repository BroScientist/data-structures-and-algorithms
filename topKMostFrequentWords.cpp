#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;

class Compare
{
public:
    bool operator() (pair<string, int> a, pair<string, int> b)
    {
        // if a and b have the same frequency, sort by the string instead
        if (a.second == b.second)
            return a.first > b.first;
        return a.second < b.second;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> freq;
        for (string& str : words)
            freq[str]++;
        
        priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> heap;
        for (auto& item : freq)
            heap.push(item);
    
        vector<string> res;
        while (k != 0)
        {
            // cout << heap.top().first << " " << heap.top().second << endl;
            res.push_back(string(heap.top().first));
            heap.pop();
            k--;
        }
        return res;
    }
};