#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        map<int, int> hashtable;
        for (int i = 0; i < mat.size(); i++)
        {
            // for each num in each row, insert the num; if the num has been seen in the row, skip it
            int lastInserted = -1;
            for (int& n : mat[i])
            {
                if (n != lastInserted)
                {
                    hashtable[n]++;
                    lastInserted = n;
                }
            }
        }
        int minCommon = INT_MAX;
        int found = false;
        for (auto& item : hashtable)
        {
            if (item.second == mat.size() && item.first < minCommon)
            {
                found = true;
                minCommon = item.first;
            }
        }
        if (!found)
            return -1;
        return minCommon;
    }
};


int main() {

    return 0;
}