#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle == "")
            return 0;
        for (int i = 0; i < haystack.size(); i++)
        {
            if (haystack[i] == needle[0] && haystack.size() - i >= needle.size())
            {
                int tmpIndex = i + 1;
                bool matching = true;
                int matchedLen = 1;  // this makes sure every character has been matched (avoid partial matches at end of string)
                for (int j = 1; j < needle.size(); j++)
                {
                    if (haystack[tmpIndex] != needle[j])
                    {
                        matching = false;
                        break;
                    }
                    tmpIndex++;
                    matchedLen++;
                }
                if (matching && matchedLen == needle.size())
                    return i;
            }
        }
        return -1;
    }
};

int main() {

    return 0;
}