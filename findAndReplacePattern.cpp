#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        int len = pattern.size();
        vector<char> chars;
        for (char& c: pattern)
        {
            if (find(chars.begin(), chars.end(), c) == chars.end())
                chars.push_back(c);
        }

        for (string& word : words)
        {
            unordered_map<char,char> freq;
            int index = 0;
            freq.insert(make_pair(chars[0], word[0]));
            char c = word[0];
            set<char> set;
            set.insert(c);
            for (int i = 1; i < word.size(); i++)
            {
                if (word[i] != c && (set.find(word[i]) == set.end()))
                {
                    c = word[i];
                    set.insert(c);
                    index++;
                    if (index == chars.size())
                        break;
                    freq.insert(make_pair(chars[index], c));
                }
            }
            if (set.size() == chars.size())
            {
                string str = "";
                for (char& c: pattern)
                    str += freq[c];
                // cout << str << endl;
                if (str == word)
                    res.push_back(word);
                
            }
        }

        return res;
    }
};

int main() {

    return 0;
}