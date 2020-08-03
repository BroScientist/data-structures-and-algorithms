#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> s;
        for (string& c : ops)
        {
            if (c != "C" && c != "D" && c != "+")
                s.push(stoi(c));
            else if (c == "C")
                s.pop();
            else if (c == "D")
                s.push(s.top() * 2);
            else
            {
                stack<int> tmp;
                int sum = 0;
                for (int i = 0; i < 2; i++)
                {
                    sum += s.top();
                    tmp.push(s.top());
                    s.pop();
                }
                for (int i = 0; i < 2; i++)
                {
                    s.push(tmp.top());
                    tmp.pop();
                }
                s.push(sum);
            }
        }
        int sum = 0;
        while (!s.empty())
        {
            sum += s.top();
            s.pop();
        }
        return sum;
    }
};
