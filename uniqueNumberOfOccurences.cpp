#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool uniqueOccurrences(vector<int>& arr) {
    map<int, int> freq;
    for (int& num : arr)
        freq[num]++;
    vector<int> occur(freq.size());
    int index = 0;
    for (auto& item : freq)
        occur[index++] = item.second;
    sort(occur.begin(), occur.end());
    auto it = unique(occur.begin(), occur.end());
    return (it == occur.end());
}

int main() {
    vector<int> arr{26,2,16,16,5,5,26,2,5,20,20,5,2,20,2,2,20,2,16,20,16,17,16,2,16,20,26,16};
    cout << uniqueOccurrences(arr) << endl;
    return 0;
}