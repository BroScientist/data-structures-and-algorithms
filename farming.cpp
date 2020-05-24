#include <iostream>
#include <string>
#include <vector>

using namespace std;

string removeVowels(string S) {

    // int i = 0;
    // for (char& c : S) {
    //     if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
    //         S.erase(S.begin() + i);
    //     }
    //     i++;
        
    // }
    // return S;
    string newS = "";
    for (char& c : S) {
        if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u') newS += c;
    }
    return newS;
}

vector<int> sortArrayByParity(vector<int>& A) {
    // for i = 0 and j = 1, if i is odd and j is even, swap the two
    // int j;
    // A.erase(A.begin() + 1);
    // A.erase(A.begin() + 1);
    // A.push_back(100);

    // int index = 0;
    // for (int& num : A) {
    //     if (num % 2 != 0) {
    //         A.push_back(num);
    //         A.erase(A.begin() + index);
    //     }
    //     else {
    //         index++;
    //     }
    // }
    // for (int& i : A) cout << i << endl;
    // return A;
    vector<int> oddNums = {};
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] % 2 != 0) {
            oddNums.push_back(A[i]);
            A.erase(A.begin() + i--);
        }
    }
    for (int& n : oddNums) A.push_back(n);
    // for (int& n : A) cout << n << endl;
    return A;
}

bool isMonotonic(vector<int>& A) {
    if (A.size() <= 1) return true;
    int j;
    // check for ascending order first
    bool ascending = true;
    bool descending = true;
    for (int i = 0; i < A.size() - 1; i++)
    {
        j = i + 1;
        if (A[i] > A[j]) ascending = false;
    }
    if (ascending) return ascending;

    // if A is not in ascending order, check again for descending
    for (int i = 0; i < A.size() - 1; i++)
    {
        j = i + 1;
        if (A[i] < A[j]) descending = false;
    }
    if (descending) return descending;
    
    return false;
}

int main() {
    vector<int> nums = {4, 0, 3, 2, 1};
    cout << isMonotonic(nums) << endl;
    return 0;
}