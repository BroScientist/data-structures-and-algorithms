#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        if (text.size() < 7)
            return 0;
        map<char, int> dict;
        for (char& c : text)
        {
            if (c == 'b' || c == 'a' || c == 'l' || c == 'o' || c == 'n')
                dict[c]++;
        }
        // "ballon" can be formed if the count of b,a,n is at least 1, and l,o is at least 2
        int count = 0;
        vector<int> elems;
        for (char& c : string("balon"))
        {
            if (dict.find(c) == dict.end())
                return 0;
            if (c == 'l' || c == 'o')
                elems.push_back(dict[c] / 2);
            else
                elems.push_back(dict[c]);
        }
        return *min_element(elems.begin(), elems.end());
    }
};