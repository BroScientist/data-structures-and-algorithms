#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
//         vector<int> pos;
//         vector<int> res(S.size()); 
//         for (int i = 0; i < S.size(); i++)
//         {
//             if (S[i] == C)
//                 pos.push_back(i);
//         }
        
//         for (auto& n : pos)
//             cout << n << endl;
//         for (int i = 0; i < S.size(); i++)
//         {
//             if (S[i] == C)
//             {
//                 res[i] = 0;
//                 continue;
//             }
//             int dist = INT_MAX;
//             for (int& p : pos)
//                 if (abs(p - i) < dist)
//                     dist = abs(p - i);
//             res[i] = dist;
//         }
        vector<int> res(S.size());
        int prev = INT_MIN / 2;
        for (int i = 0; i < S.size(); i++)
        {
            if (S[i] == C)
                prev = i;
            res[i] = i - prev;
        }
        prev = INT_MAX / 2;
        for (int i = S.size() - 1; i > -1; i--)
        {
            if (S[i] == C)
                prev = i;
            res[i] = min(res[i], prev - i);
            // if ((prev - i) < S[i])
            //     S[i] = (prev - i);
        }
        return res;
    }
};

int main() {

    return 0;
}