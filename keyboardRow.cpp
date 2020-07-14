#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        map<char, int> charToRow;
        for (char& c: string("qwertyuiop"))
            charToRow[c] = 1;
        for (char& c: string("asdfghjkl"))
            charToRow[c] = 2;
        for (char& c: string("zxcvbnm"))
            charToRow[c] = 3;
        // for (auto& item : charToRow)
        //     cout << item.first << " " << item.second << endl;
        vector<string> res;

        // for every char in word, if char does not have the same row
        for (string& word : words)
        {
            // don't forget to convert to lower case bruh
            int row = charToRow[tolower(word[0])];
            bool matching = true;
            for (int i = 1; i < word.size(); i++)
            {
                if (charToRow[tolower(word[i])] != row)
                {
                    matching = false;
                    break;
                }
            }
            if (matching)
                res.push_back(word);
        }
        return res;
        
    }
};

int main() {

    return 0;
}