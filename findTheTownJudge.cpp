#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        // outdegree = # of edges going out = people this guy trusts
        // indegree = # of edges going in = people who trust this guy
        if (trust.size() < N - 1)
            return -1;
        vector<int> outdegree(N + 1, 0), indegree(N + 1, 0);
        for (vector<int>& entry : trust)
        {
            outdegree[entry[0]]++;
            indegree[entry[1]]++;
        }
        for (int i = 1; i <= N; i++)
            if (outdegree[i] == 0 && indegree[i] == N - 1)
                return i;
        return -1;
    }
};