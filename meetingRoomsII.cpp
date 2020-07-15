#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if (intervals.size() < 1)
            return 0;
        sort(begin(intervals), end(intervals),
            [] (vector<int>& a, vector<int>& b)
             { return a[0] < b[0]; });
        // for (vector<int>& vec : intervals)
        //     cout << vec[0] << ", " << vec[1] << endl;
        
        // try to find a meeting with start time >= the current end time
        int rooms = 0;
        vector<int> tmp;
        for (int i = 0; i < intervals.size(); i++)
        {
            // if meeting has already been processed, skip it
            if (intervals[i][0] == -1 && intervals[i][1] == -1)
                    continue;
            vector<int> curr = intervals[i];
            for (int j = i + 1; j < intervals.size(); j++)
            {
                // we do not process the current meeting if one of these two conditions is true:
                    // 1. if the current meeting has the exact same start and finish time as the current one
                    // 2. if the current meeting has already been processed
                if ((intervals[j][0] == -1 && intervals[j][1] == -1) || intervals[j] == curr)
                    continue;
                // if the next meeting's start time is greater or equal to current meeting's end time, process it and mark as processed
                // also change curr to this new meeting and continue scheduling
                if (curr[1] <= intervals[j][0])
                {
                    curr = intervals[j];
                    intervals[j][0] = -1;
                    intervals[j][1] = -1;
                }
            }
            rooms++; 
        }
        return rooms;
    }
};

int main() {

    return 0;
}