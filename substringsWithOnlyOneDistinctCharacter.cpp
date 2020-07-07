#include <iostream>
#include <string>
using namespace std;

int countLetters(string S) {
        
        // formula: substrings = n * (n + 1) / 2
        string curr = "";
        curr += S[0];
        int count = 0;
        // continuously find connected chars that are the same
        for (int i = 1; i < S.size(); i++)
        {
            if (S[i] == S[i-1])
                curr += S[i];
            else
            {
                count += (curr.size() * (curr.size() + 1) / 2);
                curr = "";
                curr += 1;
            }
        }
        count += (curr.size() * (curr.size() + 1) / 2);

        return count;
        
        // hashtable approach (time limit exceeded)
        // generate all substrings
        // for every substring, use a hashtable to calculate characater frequency
        // if size of hashtable becomes 2, reset hashtable and continue
        // else reset, count++

        // map<int, int> hashtable;
        // int count = 0;
        // for (int i = 0; i < S.size(); i++)
        // {
        //     for (int j = 1; j <= S.size() - i; j++)
        //     {
        //         for (auto& c : S.substr(i, j))
        //         {
        //             hashtable[c]++;
        //             if (hashtable.size() > 1)
        //                 break;
        //         }
        //         if (hashtable.size() == 1)
        //             count++;
        //         hashtable.clear();
        //     }
        // }
        // return count;
    }