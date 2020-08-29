class Solution {
public:
    bool checkRecord(string s) {
        int absents = 0, lateStreak = 0;
        for (char& c : s)
        {
            if (c == 'A')
                absents++;
            if (absents > 1)
                return false;
            if (c == 'L')
                lateStreak++;
            else
                lateStreak = 0;
            if (lateStreak > 2)
                return false;
        }
        return true;
    }
};