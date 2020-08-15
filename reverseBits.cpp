#include <cinttypes>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int res = 0, power = 31;
        while (n != 0)
        {
            // n & 1 retrieves bit at the right most position
            // << power puts it in the reversed position in res
            res += (n & 1) << power;
            power--;
            n >>= 1;
        }
        return res;
    }
};