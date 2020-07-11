#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        map<char, int> freq, tmp;
        int count = 0;
        for (char& c : chars)
            freq[c]++;
        for (string& word : words)
        {
            for (char& c : word)
                tmp[c]++;
            bool match = true;
            for (auto& item : tmp)
            {
                if (freq.find(item.first) == freq.end())
                {
                    match = false;
                    break;
                }
                else if (tmp[item.first] > freq[item.first])
                {
                    match = false;
                    break;
                }
            }
            if (match)
                count += word.size();
            tmp.clear();
        }
        return count;
    }
};

int main() {

    return 0;
}