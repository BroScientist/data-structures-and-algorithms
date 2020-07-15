#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if (intervals.size() < 1)
            return true;
        sort(begin(intervals), end(intervals), 
            [] (vector<int>& a, vector<int>& b)
             { return a[0] < b[0]; });
        // for (vector<int>& vec : intervals)
        //     cout << vec[0] << ", " << vec[1] << endl;
        for (int i = 0; i < intervals.size() - 1; i++)
        {
            if (intervals[i][1] > intervals[i+1][0])
                return false;
        }
        return true;
    }
};

int main() {

    return 0;
}