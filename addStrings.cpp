#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        string s = "";
        vector<int> res;
        int carry = 0;
        int index1 = num1.size() - 1;
        int index2 = num2.size() - 1;
        
        while (index1 > -1 || index2 > -1)
        {
            // if the digits in a number has not been exhausted, convert it to int
            // else, simply process it as zero
            int n1 = index1 >= 0 ? num1[index1] - '0' : 0;
            int n2 = index2 >= 0 ? num2[index2] - '0' : 0;
            int sum = (n1 + n2 + carry) % 10;
            carry = (n1 + n2 + carry) / 10;
            // cout << n1 << endl;
            // cout << n2 << endl;
            // cout << sum << endl;
            // cout << carry << endl;
            res.push_back(sum);
            index1--;
            index2--;
        }
        
        if (carry != 0)
            res.push_back(carry);
        
        for (int i = res.size() - 1; i > -1; i--)
            s += res[i] + '0';
        return s;
    }
};

int main() {

    return 0;
}