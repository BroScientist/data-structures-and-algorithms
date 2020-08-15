using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        int todo = n, currBit = 2;
        while (todo != 0)
        {
            int bit = todo & 1;
            if (currBit != 2 && bit == currBit)
                return false;
            currBit = bit;
            todo = todo >> 1;
        }
        return true;
    }
};