#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        if (words.size() < 2)
            return true;
        
        map<char, int> dict;
        int index = 0;
        for (char& c : order)
            dict[c] = index++;
        
        int len = words.size() == 2 ? 1 : words.size() - 2;
        for (int i = 0; i < len; i++)
        {
            string word1 = words[i];
            string word2 = words[i+1];
            // use two pointers a and b, if word[a] > word[b] break
            // if b runs out before a does, return false
            int a = 0, b = 0;
            bool same = true;
            while (1)
            {
                if (dict[word1[a]] > dict[word2[b]])
                    return false;
                if (dict[word1[a]] != dict[word2[b]])
                    same = false;
                // if the characters are different and in order, this string is fine, break immediately
                if (!same && dict[word1[a]] < dict[word2[b]])
                    break;
                // b runs out before a and the strings are still matching, return false
                if (same && b == word2.size() - 1 && a < word1.size() - 1)
                    return false;
                if (a == word1.size() - 1 || b == word2.size() - 1)
                    break;
                a++;
                b++;
            }
        }
        return true;
    }
};