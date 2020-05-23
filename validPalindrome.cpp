#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string s) {
    // first strip off any non-alphanumeric characters and convert everything to lowercase
    // for every character in s, push it to the FRONT of the new reversed string
    // ex. for char in "abc", reversed becomes "a", then "ba" then "cba"
    if (s == "" || s.size() == 1) return true;
    transform(s.begin(), s.end(), s.begin(), ::tolower); 

    string stripped = "";
    string reversed = "";
    int i = 0;
    for (char& c : s) {
        if (isalnum(s[i])) {
            stripped += s[i];
            reversed = s[i] + reversed;
        }
        i++;
    }
    cout << stripped << endl;
    cout << reversed << endl;
   
    return (stripped == reversed);
}

int main() {
    string text1 = "A man, a plan, a canal: Panama";
    cout << isPalindrome(text1) << endl;

    string text2 = "nigga been counting me out";
    cout << isPalindrome(text2) << endl;

    string text3 = "";
    cout << isPalindrome(text3) << endl;

    string text4 = "a";
    cout << isPalindrome(text4) << endl;

    return 0;
}