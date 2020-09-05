class Solution {
public:
    int maxScore(string s) {
        int left = s[0] == '0' ? 1 : 0, right = 0;
        for (int i = 1; i < s.size(); i++)
            if (s[i] == '1')
                right++;
        int maxPoint = left + right;
        // take the i-th value and add it to left while substracting this part from right
        for (int i = 1; i < s.size() - 1; i++)
        {
            if (s[i] == '0')
                left++;
            else
                right--;
            maxPoint = max(left + right, maxPoint);
        }
        return maxPoint;
    }
};