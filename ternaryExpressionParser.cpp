#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    char eval(string exp)
    {
        if (exp[0] == 'T' || exp[0] == 'F')
        {
            if (exp[1] == '?' && exp[3] == ':')
            {
                // using ternary expression to parse ternary expression... Actual Inception
                return exp[0] == 'T' ? exp[2] : exp.back();
            }
        }
        // if expression is invalid, return x
        return 'x';
    }
    
    string parseTernary(string expression)
    {
        // if there is only one expression, simply return the result of eval
        if (expression.size() == 5)
        {
            string ans = "";
            ans += eval(expression);
            return ans;
        }
        vector<char> s;
        s.push_back(expression[0]);
        for (int i = 1; i < expression.size(); i++)
        {
            if (s.back() == ':' && expression[i+1] != '?')
            {
                s.push_back(expression[i]);
                string str = "";
                for (int j = 0; j < 5; j++)
                {
                    str = s.back() + str;
                    s.pop_back();
                }
                s.push_back(eval(str));
                string tmp;
                // sometimes after evaluating and pushing, the end of the vector forms another valid evaluation
                // in this case, repeatedly evaluate the last 5 elements until s[-5:-1] is no longer a valid sequence
                while (1)
                {
                    tmp = "";
                    if (s.size() < 5)
                        break;
                    for (int j = -5; j < 0; j++)
                        tmp += s.end()[j];
                    if (eval(tmp) != 'x')
                    {
                        for (int j = 0; j < 5; j++)
                            s.pop_back();
                        s.push_back(eval(tmp));   
                    }
                    else
                        break;
                }
                // continue to avoid pushing the element again
                continue;
            }
            // if nothing happens, simply push
            s.push_back(expression[i]);
        }
        string ans;
        ans += s[0];
        return ans;
    }
};