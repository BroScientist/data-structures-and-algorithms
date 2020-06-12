#include <iostream>
#include <string>

using namespace std;

int numJewelsInStones(string J, string S) 
{
    int total = 0;
    for (char& c : J) total += count(S.begin(), S.end(), c);
    return total;
}

int main() {
    cout << numJewelsInStones("aA", "aAAbbbb") << endl;
    cout << numJewelsInStones("z", "ZZ") << endl;
    cout << numJewelsInStones("x", "xxyyxxeesx") << endl;
    return 0;
}