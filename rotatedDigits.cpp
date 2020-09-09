class Solution {
public:
    string rotate(string s)
    {
       for (int i = 0; i < s.size(); i++)
       {
           if (s[i] == '2')
               s[i] = '5';
           else if (s[i] == '5')
               s[i] = '2';
           else if (s[i] == '6')
               s[i] = '9';
           else if (s[i] == '9')
               s[i] = '6';
       }
        return s;
    }
    
    int rotatedDigits(int N) {
        unordered_set<char> set = {'3', '4', '7'};
        string s;
        int count = 0;
        for (int i = 1; i <= N; i++)
        {
            s = to_string(i);
            bool matching = true;
            for (char& c : s)
            {
                // a number is automatically disqualified if it contains 3, 4 or 7
                if (set.find(c) != set.end())
                {
                    matching = false;
                    break;
                }
            }
            
            // if number has potential to be a good number, rotate it and check
            if (matching && rotate(s) != s)
                count++;
        }
        return count;
    }
};