#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() < 2)
            return intervals;
        // sort by end time (ascending order), if same, sort by start time
        // either start of A <= start of B OR end of A <= end of B (one must be true for merge to happen)
        sort(begin(intervals), end(intervals), [] (vector<int>& a, vector<int>& b)
         {
             return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
         });
        // for (vector<int>& vec : intervals)
        //     cout << vec[0] << " " << vec[1] << endl;
        vector<vector<int>> res;
        vector<int> curr = {intervals[0][0], intervals[0][1]};
        for (int i = 0; i < intervals.size(); i++)
        {
            if (i + 1 == intervals.size())
            {
                res.push_back(curr);
                break;
            }
            vector<int> next = intervals[i+1];
            // if either start or end of current time is between start and end of next, it is an overlapp
            if ((curr[0] >= next[0] && curr[0] <= next[1]) || (curr[1] >= next[0] && curr[1] <= next[1]))
            {
                curr[0] = min(curr[0], next[0]);
                curr[1] = max(curr[1], next[1]);
            }
            // else if next can be placed inside curr
            else if ((next[0] >= curr[0] && next[0] <= curr[1]) || (next[1] >= curr[0] && next[1] <= curr[1]))
            {
                curr[0] = min(curr[0], next[0]);
                curr[1] = max(curr[1], next[1]);
            }
            else
            {
                res.push_back(curr);
                curr = {next[0], next[1]};
            }
        }
        return res;
    }
};

int main() {

    return 0;
}