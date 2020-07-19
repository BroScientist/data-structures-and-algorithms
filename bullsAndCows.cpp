#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        // A = exact matches of both digit and index
        // B = digits match but not index
        unordered_map<int,int> freq;
        for (char& c : secret)
            freq[(c - '0')]++;
        unordered_map<int,int> freq2;
        for (char& c : guess)
            freq2[(c - '0')]++;
        // for (int i = 0; i < secret.size(); i++)
        //     numToIndex[(secret[i] - '0')] = i;
        // for (auto& item : freq)
        //     cout << item.first << " " << item.second << endl;
        string res = "";
        int bulls = 0, cows = 0;
        for (int i = 0; i < guess.size(); i++)
        {
            int num = guess[i] - '0';
            if (guess[i] == secret[i])
            {
                bulls++;
                freq[num]--;
                if (freq[num] == 0)
                    freq.erase(num);
                freq2[num]--;
                if (freq2[num] == 0)
                    freq2.erase(num);
            }
        }
        
        for (int i = 0; i < guess.size(); i++)
        {
            int num = guess[i] - '0';
            if (freq.find(num) != freq.end() && freq2.find(num) != freq2.end())
            {
                cows++;
                freq[num]--;
                if (freq[num] == 0)
                    freq.erase(num);
                freq2[num]--;
                if (freq2[num] == 0)
                    freq2.erase(num);
            }
        }
        
        res += to_string(bulls); res += 'A';
        res += to_string(cows); res += 'B';

        return res;
    }
};

int main() {

    return 0;
}