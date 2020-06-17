#include <iostream>
#include <vector>

using namespace std;

int numOfDigit(int num)
{
    if (num == 0) return 1;
    int digit = 0;
    while (num != 0)
    {
        digit++;
        num /= 10;
    }
    return digit;
}

int findNumbers(vector<int>& nums) {
    int count = 0;
    for (int& n : nums)
    {
        if (numOfDigit(n) % 2 == 0) count++;
    }        
    return count;
}

int main() {
    vector<int> vec{555,901,482,1771};
    cout << findNumbers(vec) << endl;
    return 0;
}