class Solution {
public:
    int binaryGap(int N) {
        deque<int> digits;
        while (N != 0)
        {
            int bit = N & 1;
            // cout << bit << endl;
            digits.push_front(bit);
            N >>= 1;
        }
        int start = -1, end = -1, maxGap = 0;
        for (int i = 0; i < digits.size(); i++)
        {
            if (start == -1 && digits[i] == 1)
                start = i;
            else if (digits[i] == 1)
            {
                end = i;
                maxGap = max(maxGap, end - start);
                start = i;
            }
            
        }
        return (start == -1 || end == -1) ? 0 : maxGap;
    }
};