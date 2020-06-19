#include <iostream>
#include <string>
using namespace std;

string freqAlphabets(string s) {
    string output;
    int index = 0;
    string temp;
    string letters = "aabcdefghijklmnopqrstuvwxyz";
    while (index < s.size())
    {
        if (index + 2 < s.size() && s[index+2] == '#')
        {
            temp += s[index];
            temp += s[index + 1];
            output += letters[stoi(temp)];
            index += 3;
        }
        else
        {
            temp += s[index];
            output += letters[stoi(temp)];
            index++;
        }
        temp = "";
    }
    // cout << output << endl;
    return output;
}

int main() {

    freqAlphabets("25#");
    return 0;
}