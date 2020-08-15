using namespace std;

class Solution {
public:
    int primeBits(int num)
    {
        int bits = 0, todo = num;
        while (todo != 0)
        {
            if (todo & 1)
                bits++;
            todo >>= 1;
        }
        return (bits == 2 || bits == 3 || bits == 5 || bits == 7 ||
                bits == 11 || bits == 13 || bits == 17 || bits == 19);
        // cout << num << " " << bits << endl;
        // if (bits == 1)
        //     return false;
        // for (int i = 2; i <= bits / 2; i++) {
        //     if (bits % i == 0)
        //         return false;
        // }
        // return true;
    }
    
    int countPrimeSetBits(int L, int R) {
        int count = 0;
        for (int n = L; n <= R; n++)
            if (primeBits(n))
                count++;
        return count;
    }
};