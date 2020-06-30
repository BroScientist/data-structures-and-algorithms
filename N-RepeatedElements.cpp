#include <iostream>
#include <vector>
#include <map>

using namespace std;

int repeatedNTimes(vector<int>& A) {
    map<int, int> hashtable;
    for (int& num : A)
        hashtable[num]++;
    // int ans, max_freq = 0;
    // for (auto item : hashtable)
    // {
    //     if (item.second > max_freq)
    //     {
    //         max_freq = item.second;
    //         ans = item.first;
    //     }
    // }
    for (auto& item : hashtable)
    {
        if (item.second == A.size() / 2)
            return item.first;
    }
    return 0;
}

int main() {
    vector<int> vec = {5,1,5,2,5,3,5,4};
    cout << repeatedNTimes(vec) << endl;

    return 0;
}