#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> stack;
        vector<int> res(T.size(), 0);
        for (int i = 0; i < T.size(); i++)
        {
            int currTmp = T[i];
            while (!stack.empty() && currTmp > T[stack.top()])
            {
                res[stack.top()] = i - stack.top();
                stack.pop();   
            }
            stack.push(i);
        }
        
        return res;
    }
};

int main() {

    return 0;
}