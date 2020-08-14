#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

class Compare
{
public:
    // custom compare class for MIN heap
    bool operator() (pair<int,int>& a, pair<int,int>& b)
    {
        return a.second > b.second;
    }
};

class FirstUnique {
public:
    unordered_map<int, int> freq;
    priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> heap; // min heap of pairs, where the smaller pair.second gets retrieved first
    int order = 1; // keep track of insertion order
    FirstUnique(vector<int>& nums) {
        for (int& n : nums)
            add(n);
    }
    
    int showFirstUnique() {
        while (!heap.empty())
        {
            int elem = heap.top().first;
            // if top of heap has frequency of 1, return it but DO NOT pop it
            if (freq[elem] == 1)
                return elem;
            // only pop when the frequency of the top element isn't 1, which means it's useless
            heap.pop();
        }
        // if heap becomes empty and a valid value still hasn't been found, return -1
        return -1;
    }
    
    void add(int value) {
        // update frequency of value, but only push it to heap if it's frequency is 1 (unique)
        freq[value]++;
        if (freq[value] == 1)
            heap.push(make_pair(value, order++));
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */