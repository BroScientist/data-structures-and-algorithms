#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int,int> sums;
        for (int& a : A)
            for (int& b : B)
                sums[a + b]++;
        int count = 0;
        for (int& c : C)
            for (int& d : D)
                if (sums.find(-(c + d)) != sums.end())
                    count += sums[-(c + d)];
        return count;
    }
};
