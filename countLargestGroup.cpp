#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int digitSum(int n)
    {
        int sum = 0;
        while (n != 0)
        {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
    int countLargestGroup(int n) {
        unordered_map<int,vector<int>> numToSum;
        int maxSize = 0;
        for (int i = 1; i <= n; i++)
        {
            int digits = digitSum(i);
            numToSum[digits].push_back(i);
            if (numToSum[digits].size() > maxSize)
                maxSize = numToSum[digits].size();
        }
        int count = 0;
        for (auto& item : numToSum)
        {
            if (item.second.size() == maxSize)
                count++;
        }
        return count;
    }
};
