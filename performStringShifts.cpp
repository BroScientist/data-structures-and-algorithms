class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        // left shift = take left portion and append it to right portion
        // right shift = take right portion and append left portion to it
        int len = s.size();
        if (len == 1)
            return s;
        string left, right;
        for (vector<int>& move : shift)
        {
            if (move[0] == 0)
            {
                left = s.substr(0, move[1]);
                right = s.substr(move[1]);
                s = right + left;
            }
            else
            {
                left = s.substr(len - move[1]);
                right = s.substr(0, len - move[1]);
                s = left + right;
            }
        }
        return s;
    }
};