#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        // first, compute sums and difference
        // find a pair a, b such that a is larger than b and a - b = diff / 2
        int sum1 = accumulate(begin(A), end(A), 0);
        int sum2 = accumulate(begin(B), end(B), 0);
        int diff = abs(sum2 - sum1);
        vector<int> tmp;
        bool flag = false;
        if (sum1 > sum2)
        {
            tmp = A;
            A = B;
            B = tmp;
            flag = true;
        }
        // check the larger array
        unordered_map<int, int> hashtable;
        for (int& n : B)
        {
            hashtable[n] = (n - diff / 2);
        }
        // for (auto& item : hashtable)
        //     cout << item.first << " " << item.second << endl;
        unordered_map<int, int> hashtable2;
        for (int& n : A)
            hashtable2[n]++;
        vector<int> res(2);
        for (int& n : B)
        {
            int complement = hashtable[n];
            if (hashtable2.find(complement) != hashtable2.end())
            {
                res[0] = complement;
                res[1] = n;
                if (flag)
                    reverse(begin(res), end(res));
                return res;
            }
        }
        return res;
    }
};

int main() {

    return 0;
}