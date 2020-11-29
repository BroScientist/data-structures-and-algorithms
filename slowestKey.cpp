class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int index = 0, maxGap = releaseTimes[0];
        char res = keysPressed[0];
        for (int i = 1; i < releaseTimes.size(); i++)
        {
            int gap = releaseTimes[i] - releaseTimes[i - 1];
            if(gap >= maxGap)
            {
                // if gap equals max gap, compare the chars lexicographically
                // otherwise simply change res to the current character
                res = gap == maxGap ? max(res, keysPressed[i]) : keysPressed[i];
                maxGap = gap;
            }
        }
        return res;
    }
};