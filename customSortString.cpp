#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string customSortString(string S, string T) {
        unordered_map<char,int> charToRank;
        set<char> seen;
        // for every char in S, map it to a rank. The later that char appears in S, the higher the rank
        for (int i = 0; i < S.size(); i++)
        {
            charToRank[S[i]] = i;
            seen.insert(S[i]);
        }

        // for chars we have not seen in S, their rank can be anything
        // for the sake of simplicity, set these unseen character's rank to be bigger than the current largest rank
        int rank = S.size();
        for (char& c : string("abcdefghijklmnopqrstuvwxyz"))
        {
            if (seen.find(c) == seen.end())
                charToRank[c] = rank++;
        }

        // simply sort T with the order we just established and return the result
        sort(begin(T), end(T), [&charToRank] (char& a, char& b) { return charToRank[a] < charToRank[b]; });
        
        return T;
    }
};