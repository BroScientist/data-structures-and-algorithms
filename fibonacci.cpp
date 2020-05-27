
#include <iostream>
using namespace std;
 
int fib(int N) {
    if (N == 0) return 0;
    if (N == 1 || N == 2) return 1;
    return fib(N-1) + fib(N-2); 
}

int main()
{
    cout << fib(0) << endl;
    cout << fib(4) << endl;
    cout << fib(6) << endl;
}