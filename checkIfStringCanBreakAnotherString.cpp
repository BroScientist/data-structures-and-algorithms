class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(begin(s1), end(s1));
        sort(begin(s2), end(s2));
        // bal tracks the overall balance of the string
        int bal = 0, same = 0;
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] > s2[i])
                bal++;
            else if (s2[i] > s1[i])
                bal--;
            else
                same++;
        }
        // cout << abs(bal) + same << endl;
        return abs(bal) + same == s1.size();
    }
};