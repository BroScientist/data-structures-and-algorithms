#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(begin(g), end(g));
        sort(begin(s), end(s));
        int count = 0;
        for (int i = 0; i < g.size(); i++)
        {
            // since list is sorted, if this child cannot be satisfied with any cookie, the rest of them won't either
            // in that case, we break early
            bool found = false;
            for (int j = 0; j < s.size(); j++)
            {
                if (s[j] >= g[i])
                {
                    count++;
                    s.erase(s.begin() + j);
                    found = true;
                    break;
                }
            }
            if (!found)
                break;
        }
        return count;
    }
};

int main() {

    return 0;
}