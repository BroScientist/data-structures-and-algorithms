#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, int> freqS, freqT;
        int steps = 0;
        for (char& c : s)
            freqS[c]++;
        for (char& c : t)
            freqT[c]++;
        for (auto& item : freqS)
        {
            char c = item.first;
            if (freqT.find(c) != freqT.end())
            {
                if (freqT[c] < freqS[c])
                    steps += freqS[c] - freqT[c];
            }
            else
                steps += freqS[c];
        }
        return steps;
    }
};
