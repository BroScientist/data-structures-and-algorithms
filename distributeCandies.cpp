#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

class Compare {
public:
    bool operator() (pair<int, int> a, pair<int, int> b)
    {
        return a.second < b.second;
    }
};

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        map<int, int> hashtable;
        // there is absolutely no need to use a priortiy queue for this question
        // I just happen to remember the syntax
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> heap;
        for (int& n : candies)
            hashtable[n]++;
        for (auto& item : hashtable)
        {
            heap.push(make_pair(item.first, item.second));
            if (heap.size() > candies.size() / 2)
                heap.pop();
        }
        int kinds = 0;
        while (!heap.empty())
        {
            kinds++;
            heap.pop();
        }
        return kinds;
    }
};

int main() {

    return 0;
}