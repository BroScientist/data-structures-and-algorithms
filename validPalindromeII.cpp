class Solution {
public:
    bool isPalindrome(string s, int start, int end)
    {
        int i = start, j  = end; 
        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        int i = 0, j  = s.size() - 1; 
        while (i < j)
        {
            if (s[i] != s[j])
            {
                // try removing the character at i, if this create a palindrome, return true
                if (isPalindrome(s, i + 1, j))
                    return true;
                // similarily, try removing the character at j and see if it results in a palindrome
                if (isPalindrome(s, i, j - 1))
                    return true;
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};