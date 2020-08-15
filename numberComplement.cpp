#include <math.h>
using namespace std;

class Solution {
public:
    int findComplement(int num) {
        // constructing a 1-bits bit mask with length equal to the num's binary representation
        int len = (int) log2(num) + 1;
        int bitmask = (1 << len) - 1;
        return bitmask ^ num;
        
        // flipping bits one by one
        // int todo = num, bit = 1;
        // while (todo != 0)
        // {
        //     num = num ^ bit;
        //     todo = todo >> 1;
        //     bit = bit << 1;
        // }
        // return num;
    }
};