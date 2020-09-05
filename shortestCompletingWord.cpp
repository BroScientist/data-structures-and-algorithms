class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        // construct the target string by parsing letters from the input string
        string target = "";
        for (char& c : licensePlate)
            if (isalpha(c))
                target += tolower(c);
        
        // create a multiset of characters to allow easy assess to the number of characters
        multiset<char> targetFreq;
        for (char& c : target)
            targetFreq.insert(c);
        
        // stable sort the words vector by length of string
        // the original ordering of strings of equal length must be preserved
        stable_sort(begin(words), end(words), [] (string s1, string s2)
             {
                 return s1.size() < s2.size();
             });
        
        for (string& word : words)
        {
            // process the current word if it is at least as long as the target string
            if (word.size() >= target.size())
            {
                // for every character c, check if the count of c in the current word is greater or equal to its count in the target string
                bool matching = true;
                for (char c : targetFreq)
                    if (count(begin(word), end(word), c) < targetFreq.count(c))
                    {
                        matching = false;
                        break;
                    }
                if (matching)
                    return word;
            }
        }
        
        return "";
        
    }
};