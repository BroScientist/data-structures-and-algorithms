#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        // compute the rank of each number (sort first to make that calculation easy) and store in dict
        // populate res using this hashtable
        vector<int> copy = arr;
        sort(begin(arr), end(arr));
        vector<int> res(arr.size());
        int rank = 1;
        unordered_map<int, int> numToRank;
        for (int& n : arr)
        {
            if (numToRank.find(n) == numToRank.end())
                numToRank[n] = rank++;
        }
        // for (auto& item : numToRank)
        //     cout << item.first << " " << item.second << endl;
        for (int i = 0; i < arr.size(); i++)
            res[i] = numToRank[copy[i]];
        return res;
    }
};

int main() {

    return 0;
}