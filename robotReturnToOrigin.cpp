#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        vector<int> pos = {0, 0};
        for (char& c : moves)
        {
            switch(c)
            {
                case 'U':
                    pos[0]++;
                    break;
                case 'D':
                    pos[0]--;
                    break;
                case 'R':
                    pos[1]++;
                    break;
                case 'L':
                    pos[1]--;
                    break;
            }
        }
        return (pos[0] == 0 && pos[1] == 0);
    }
};

int main() {

    return 0;
}