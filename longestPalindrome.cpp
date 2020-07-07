#include <iostream>
#include <map>
using namespace std;

int longestPalindrome(string s) {
        // build a hashtable of character frequencies
        map<char, int> hashtable;
        for (char& c : s)
            hashtable[c]++;
        // all even frequencies can be formed into palindrome, so they are added to count directly
        // plus odd - 1
        // plus one, if still possbile (to form middle element)
        int count = 0;
        bool hasRemaining = false;
        for (auto& item : hashtable)
        {
            if (item.second % 2 == 0)
                count += item.second;
            else
            {
                count += item.second - 1;
                hasRemaining = true;
            }
            // cout << item.first << " " << item.second << endl;
        }
        return count + hasRemaining;

    }