#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> res;

        int i = 0, j = 0;
        while (i < A.size() && j < B.size())
        {
            int start = max(A[i][0], B[j][0]);
            int end = min(A[i][1], B[j][1]);
            if (start <= end)
            {
                vector<int> curr;
                curr.push_back(start);
                curr.push_back(end);
                res.push_back(curr);                
            }
            // if end time of A is before end time of B, since list is sorted, A is no longer possible to get matched with an interval
            if (A[i][1] < B[j][1])
                i++;
            // if this is not the case, B[j] has been processed and we increment j
            else
                j++;
        }
        return res;
        
        // naive solution:
        // for (vector<int> interval1 : A)
        // {
        //     int start1 = interval1[0];
        //     int end1 = interval1[1];
        //     bool f1 = false, f2 = false;
        //     for (vector<int> interval2 : B)
        //     {
        //         if (f1 && f2)
        //             break;
        //         int start2 = interval2[0];
        //         int end2 = interval2[1];
        //         if (start2 > end1)
        //         {
        //             f1 = true;
        //             continue;
        //         }
        //         if (end2 < start1)
        //         {
        //             f2 = true;
        //             continue;
        //         }
        //         vector<int> curr;
        //         curr.push_back(max(start1, start2));
        //         curr.push_back(min(end1, end2));
        //         res.push_back(curr);
        //     }
        // }
    }
};

int main() {

    return 0;
}