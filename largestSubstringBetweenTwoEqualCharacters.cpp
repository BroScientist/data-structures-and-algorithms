class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        // these two arrays store the indexes where a character first and last occurs
        vector<int> startIndexes(26, -1), endIndexes(26, -1);
        int maxLen = -1;
        
        for (int i = 0; i < s.size(); i++)
        {
            int charIndex = s[i] - 96 - 1; // converts char to index in array
            // if the current character has not been seen before, initialize it with i
            if (startIndexes[charIndex] == -1)
                startIndexes[charIndex] = i;
            // otherwise, this character has occured before and we compute the length of the substring, updating maxLen if it is longer
            else
            {
                endIndexes[charIndex] = i;
                maxLen = max(maxLen, i - startIndexes[charIndex] - 1);
            }
        }

        return maxLen;
    }
};