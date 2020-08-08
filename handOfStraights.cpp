#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        map<int,int> freq;
        for (int& n : hand)
            freq[n]++;
        
        while (!freq.empty())
        {
            // set starting point as the current first element of the hashtable
            int head = freq.begin()->first;
            int len = 1;
            
            // decrement the frequency of the head element. Erase this key if frequency becomes 0
            freq[head]--;
            if (freq[head] == 0)
                freq.erase(head);
            
            // loop and continously look for head + 1 until length reaches k
            // if at any point head + 1 is not found, return false
            while (len != W)
            {
                if (freq.find(head + 1) == freq.end())
                    return false;
                head = head + 1;
                freq[head]--;
                if (freq[head] == 0)
                    freq.erase(head);
                len++;
            }

        }
        
        return true;
    }
};
