#include <iostream>
#include <vector>

using namespace std;

int arrangeCoins(int n) {
    if (n == 0 || n == 1)
        return n;
    int fullRows = 0;
    int rowCoins = 1;
    bool increasing = true;
    while (n >= rowCoins)
    {
        // if row has reached n, make increasing false so we start counting backward
        if (rowCoins == n)
            increasing = false;
        // if row has decreased to 1, swtich back to increasing
        else if (rowCoins == 1 && !increasing)
            increasing = true;
        n -= rowCoins;
        if (increasing)
            rowCoins++;
        else
            rowCoins--;
        fullRows++;
    }
    // cout << fullRows << endl;
    return fullRows;    
}

int main() {
    arrangeCoins(1);
    arrangeCoins(5);
    arrangeCoins(100);
    return 0;
}