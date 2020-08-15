using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n < 0)
            return false;
        int todo = n, ones = 0;
        while (todo != 0)
        {
            if (todo & 1 == 1)
                ones++;
            todo >>= 1;
        }
        return ones == 1;
    }
};