#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> hashtable;
        for (char& c : s)
            hashtable[c]++;
        unordered_map<char,int> hashtable2;
        
        for (char& c : t)
        {
            if (hashtable.find(c) == hashtable.end())
                return c;
            hashtable2[c]++;
        }
        for (auto& item : hashtable2)
        {
            if (hashtable2[item.first] > hashtable[item.first])
                return item.first;
        }
        return 'c';
    }
};

int main() {

    return 0;
}