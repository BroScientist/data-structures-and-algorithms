#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    bool canPermutePalindrome(string s) {
        map<char, int> freq;
        for (char& c : s)
            freq[c]++;
        bool used = false;
        for (auto& item : freq)
        {
            // cout << item.first << " " << item.second << endl;
            if (!used && item.second % 2 != 0)
                used = true;
            else if (used && item.second % 2 != 0)
                return false;
        }
        return true;
    }
};

int main() {

    return 0;
}