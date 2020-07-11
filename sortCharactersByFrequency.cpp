#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>

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
    string frequencySort(string s) {
        // find freq of each char using hashtable
        map<char, int> hashtable;
        for (char& c : s)
            hashtable[c]++;
        
        // use a max heap of pairs to sort the hashtable
        priority_queue<pair<char, int>, vector<pair<char, int>>, Compare> heap;
        for (auto& item : hashtable)
            heap.push(make_pair(item.first, item.second));
        
        // append everything to the answer string
        string res = "";
        while (!heap.empty())
        {
            for (int i = 0; i < heap.top().second; i++)
                res += heap.top().first;
            heap.pop();
        }
        return res;
    }
};

int main() {

    return 0;
}