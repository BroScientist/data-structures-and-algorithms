#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(begin(costs), end(costs), 
            [](vector<int>& a, vector<int>& b)
               { return a[0] - a[1] < b[0] - b[1]; });
        // for (vector<int>& v : costs)
        //     cout << v[0] << ", " << v[1] << endl; 
        int total = 0;
        int n = costs.size() / 2;
        for (int i = 0; i < n; i++)
            total += costs[i][0] + costs[i+n][1];
        return total;
    }
};

int main() {

    return 0;
}