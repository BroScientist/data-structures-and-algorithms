#include <iostream>
using namespace std;

class Solution {
public:
    int countOdds(int low, int high) {
        // case 1: both odd
        if (low % 2 != 0 && high % 2 != 0)
            return ((high - low) / 2) + 1;
            
        // case 2: one even one odd
        if ((low % 2 != 0 && high % 2 == 0) || (low % 2 == 0 && high % 2 != 0))
            return ((high - low) / 2) + 1;

        // case 3: both even
        return (high - low) / 2;
    }
};

int main() {

    return 0;
}