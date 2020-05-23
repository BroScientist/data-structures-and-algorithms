#include <iostream>
using namespace std;

int mySqrt(int unsigned x) {
    if (x < 2) return x;
    if (x == 2 || x == 3) return 1;
    if (x == 5) return 2;

    for (unsigned int i = 1 ; i <= x/2; i++)
    {
        if (i * i == x) return i;
        if (i * i > x) return i-1;
    }
    return -1;
}

int main() {
    cout << mySqrt(0) << endl;
    cout << mySqrt(1) << endl;
    cout << mySqrt(2) << endl;
    cout << mySqrt(3) << endl;
    cout << mySqrt(4) << endl;
    cout << mySqrt(5) << endl;
    cout << mySqrt(64) << endl;
    cout << mySqrt(101) << endl;
    cout << mySqrt(458) << endl;
    cout << mySqrt(2147483647) << endl;
    return 0;
}