class Solution {
public:
    int countSegments(string s) {
        if (s.size() == 0)
            return 0;
        int count = 0, i = 0;
        while (i != s.size())
        {
            if (s[i] != ' ')
            {
                count++;
                while (s[i] != ' ' && i != s.size())
                    i++;
            }
            else
            {
                while (s[i] == ' ' && i != s.size())
                    i++;
            }
        }
        return count;
    }
};