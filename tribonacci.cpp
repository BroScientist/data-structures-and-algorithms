#include <iostream>
#include <map>
using namespace std;

int* results;
int trib(int n, int* results)
{
    // if trib(n) has already been seen, simply retrive it from the array
    if (results[n] != 0) return results[n];
    // otherwise, compute trib(n) and store it in results
    if (n == 0) return 0;
    if (n == 1 || n == 2) return 1;
    int current = 0;
    current = trib(n-3, results) + trib(n-2, results) + trib(n-1, results);
    results[n] = current;
    return current; 
}

int tribonacci(int n) {
    results = new int[n+1];
    // the Nth trib number is: trib(n-3) + trib(n-2) + trib(n-1)
    return trib(n, results);
}

int main()
{
    cout << tribonacci(1) << endl;
    cout << tribonacci(2) << endl;
    cout << tribonacci(3) << endl;
    cout << tribonacci(25) << endl;
}