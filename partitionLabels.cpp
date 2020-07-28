#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> res;
        int start = 0;
        unordered_map<char, int> charLastIndex, seen;
        for (int i = 0; i < S.size(); i++)
            charLastIndex[S[i]] = i;
        
        while (start != S.size())
        {
            char curr = S[start];
            seen[curr]++;
            int currEnd = charLastIndex[curr];
            int i = start;
            while (i != currEnd)
            {
                seen[S[i]]++;
                if (charLastIndex[S[i]] > currEnd)
                    currEnd = charLastIndex[S[i]];
                i++;
            }
            currEnd++;
            res.push_back(currEnd - start);
            start = currEnd;
            seen.clear();
        }
        return res;
    }
};