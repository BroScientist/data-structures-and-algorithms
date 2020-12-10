class Solution {
public:
    int smallestRepunitDivByK(int K) {
        int remainder = 0;
        for (int lengthN = 1; lengthN <= K; lengthN++)
        {
            remainder = (remainder * 10 + 1) % K;
            if (remainder == 0)
                return lengthN;
        }
        return -1;
    }
};