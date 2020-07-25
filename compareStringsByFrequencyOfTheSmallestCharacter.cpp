#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int freqOfMin(string s)
    {
        char minChar = *min_element(begin(s), end(s));
        return count(begin(s), end(s), minChar);
    }
    
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> res;
        vector<int> wordsFreqScore(words.size());
        for (int i = 0; i < words.size(); i++)
            wordsFreqScore[i] = freqOfMin(words[i]);
            
        for (string& q : queries)
        {
            int count = 0, freq = freqOfMin(q);
            for (int& score : wordsFreqScore)
                if (freq < score)
                    count++;
            res.push_back(count);
        }
        return res;
    }
};

int main() {

    return 0;
}