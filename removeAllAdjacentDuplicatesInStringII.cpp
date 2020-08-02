#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s, int k) {
        // pair.first = the character, pair.second = consecutive occurences of that char
        stack<pair<char,int>> stack;
        for (char& c : s)
        {
            int consec = 1;
            if (!stack.empty() && c == stack.top().first)
                consec += stack.top().second;
            stack.push(make_pair(c, consec));
            while (consec == k)
            {
                for (int i = 0; i < k; i++)
                    stack.pop();
                consec = 0;
            }
        }
        string res(stack.size(), 'a');
        for (int i = res.size() - 1; i > -1; i--)
        {
            res[i] = stack.top().first;
            stack.pop();
        }
        return res;
    }
};
