#include <iostream>
using namespace std;

class Solution {
public:
    int divides(int num, int divisor)
    {
        // continuously divide num until it is no longer divisible by divisor
        while (num % divisor == 0)
        {
            num /= divisor;
        }
        // return the reduced number
        return num;
    }
    bool isUgly(int num) {
        // how is zero a testcase bruh
        if (num == 0)
            return false;
        // divide num by 2, 3 and 5 (order doesn't matter) using the divide function
        num = divides(num, 2);
        num = divides(num, 3);
        num = divides(num, 5);
        // if number reduces to 1, it means the number only has prime factors 2, 3, and 5
        return (num == 1) ? 1 : 0;
    }
};