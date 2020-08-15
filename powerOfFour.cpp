using namespace std;

class Solution {
public:
    bool isPowerOfFour(int num) {
        // power of four = leading 1 + even number of zeros in binary representation
        if (num < 0)
            return false;
        int todo = num, ones = 0, zeros = 0;
        while (todo != 0)
        {
            if (todo & 1 == 1)
                ones++;
            else
                zeros++;
            todo >>= 1;
        }
        return ones == 1 && zeros % 2 == 0;
    }
};