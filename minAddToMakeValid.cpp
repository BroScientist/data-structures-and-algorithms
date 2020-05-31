#include <iostream>
#include <vector>
using namespace std;

int minAddToMakeValid(string S) {
    vector<char> stack;
    // if stack is empty, push the current char and continue
    // if stack is not empty, check the current char with the previous one
    // if these two chars form a valid parenthesis, pop and continue
    // if these two chars aren't valid, just push the current char
    for (char& c : S) {
        if (stack.empty()) { stack.push_back(c); continue;}
        if (c == ')' && stack.back() == '(') {stack.pop_back(); continue;}
        if (c == '}' && stack.back() == '{') {stack.pop_back(); continue;}
        if (c == ']' && stack.back() == '[') {stack.pop_back(); continue;}
        stack.push_back(c);
    }

    // the number of leftover symbols in the stack represent the solution
    return stack.size();
}


int main() {
    // cout << isValid("(){}[]") << endl;
    cout << minAddToMakeValid("))") << endl;
    cout << minAddToMakeValid("()(())") << endl;
}