#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numKLenSubstrNoRepeats(string S, int K) {
        if (K > S.size())   
            return 0;
        unordered_map<char, int> hashtable;
        int count = 0;
        string sub = "";
        for (int i = 0; i < K; i++)
        {
            sub += S[i];
            hashtable[S[i]]++;
        }
        if (hashtable.size() == K)
            count++;
        for (int i = K; i < S.size(); i++)
        {
            if (hashtable[sub[0]] == 1)
                hashtable.erase(sub[0]);
            else
                hashtable[sub[0]]--;
            sub.erase(sub.begin());
            sub += S[i];
            hashtable[S[i]]++;
            if (hashtable.size() == K)
                count++;
        }
        return count;
    }
};

int main() {

    return 0;
}