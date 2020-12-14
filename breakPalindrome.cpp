class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        
        if (n == 1)
            return "";
        
        unordered_map<char,int> freq;
        for (char& c : palindrome)
            freq[c]++;
        
        // two speical cases:
            // 1 palindrome is all a
            // 2 palindrome is all a except one character
        // in either case, replace the last character with b and return
        if ((freq.size() == 1 && freq['a'] == n) || freq['a'] == n - 1)
        {
            palindrome.back() = 'b';
            return palindrome;
        }
        
        // otherwise, scan for the first char that is not a and replace it with a
        for (int i = 0; i < palindrome.size(); i++)
        {
            if (palindrome[i] != 'a')
            {
                palindrome[i] = 'a';
                break;
            }
        }
        
        return palindrome;
    }
};