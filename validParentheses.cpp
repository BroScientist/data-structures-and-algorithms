#include <iostream>
#include <vector>
using namespace std;

bool isValid(string s) {
    vector<char> stack;
    for (char& c : s) {
        if (c == '(' || c == '{' || c == '[') {stack.push_back(c); continue;}
        if (c == ')' || c == '}' || c == ']') {
            if (stack.empty()) return false;
        }
        if (c == ')' && stack.back() == '(') {stack.pop_back(); continue;}
        if (c == '}' && stack.back() == '{') {stack.pop_back(); continue;}
        if (c == ']' && stack.back() == '[') {stack.pop_back(); continue;}
        else {
            return false;}
    }
    return (stack.size() == 0);
}


int main() {
    // cout << isValid("(){}[]") << endl;
    cout << isValid(")") << endl;
    return 0;
}