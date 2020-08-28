class Solution {
public:
    bool isVowel(char c)
    {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    
    string reverseVowels(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j)
        {
            if (!isVowel(s[i]))
                i++;
            if (!isVowel(s[j]))
                j--;
            if (isVowel(s[i]) && isVowel(s[j]))
            {
                char tmp = s[i];
                s[i] = s[j];
                s[j] = tmp;
                i++;
                j--;
            }
        }
        return s;
    }
};