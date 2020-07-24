#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string sortString(string s) {

        // put every item.first in freq into a temp string
        // sort that shit, append to res
        // sort in reverse order for the next iter
        unordered_map<char, int> freq;
        for (char& c : s)
            freq[c]++;
        bool flag = false;
        string res = "";
        int i = 0;
        while (i != s.size())
        {
            string tmp = "";
            // for (auto it = freq.cbegin(); it != freq.cend(); )
            // {
            //     tmp += it->first;
            //     it->second = it->second - 1;
            //     if (it.second == 0)
            //         it = freq.erase(it);
            //     else
            //         ++it;
            // }
            for (auto& item : freq)
            {
                if (item.second == 0)
                    continue;
                tmp += item.first;
                item.second--;
                i++;
            }
            sort(begin(tmp), end(tmp));
            if (!flag)
                flag = true;
            else
            {
                reverse(begin(tmp), end(tmp));
                flag = false;
            }
            res += tmp;
        }
        return res;
    }
};
