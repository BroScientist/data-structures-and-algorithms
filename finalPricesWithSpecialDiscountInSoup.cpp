#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        // stack of pairs of index and number
        stack<pair<int, int>> s;
        vector<int> res(prices.size());
        int i = 0;
        for (int& n : prices)
        {
            while (!s.empty() && n <= s.top().second)
            {
                res[s.top().first] = s.top().second - n;
                s.pop();
            }
            s.push(make_pair(i++, n));
        }
        while (!s.empty())
        {
            res[s.top().first] = s.top().second;
            s.pop();
        }
        return res;
    }
};
