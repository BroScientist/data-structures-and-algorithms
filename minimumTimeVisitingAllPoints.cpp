#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // this question was lul
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        pair<int, int> curr(points[0][0], points[0][1]);
        int steps = 0;
        for (int i = 1; i < points.size(); i++)
        {
            steps += max(abs(points[i][0] - curr.first), abs(points[i][1] - curr.second));
            curr = make_pair(points[i][0], points[i][1]);
        }
        return steps;
    }
};