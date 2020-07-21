#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Compare
{
public:
    bool operator() (pair<int, vector<int>> a, pair<int, vector<int>> b)
    {
        int count1 = count(begin(a.second), end(a.second), 1);
        int count2 = count(begin(b.second), end(b.second), 1);
        return count1 == count2 ? a.first < b.first : count1 < count2;
    }
};

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, Compare> heap;
        int index = 0;
        for (vector<int>& vec : mat)
        {
            heap.push(make_pair(index++, vec));
            if (heap.size() > k)
                heap.pop();
        }
        vector<int> res(heap.size());
        for (int i = k - 1; i >= 0; i--)
        {
            res[i] = heap.top().first;
            heap.pop();
        }
        return res;
    }
};

int main() {

    return 0;
}