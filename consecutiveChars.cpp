#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int maxPower(string s) {
        char prev = s[0];
        int currConsec = 1, maxConsec = 1;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == prev)
            {
                currConsec++;
                if (currConsec > maxConsec)
                    maxConsec = currConsec;
            }
            else
            {
                currConsec = 1;
                prev = s[i];
            }
                
        }
        return maxConsec;
    }
};

int main() {

    return 0;
}