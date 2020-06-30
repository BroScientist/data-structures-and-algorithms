#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
    map<int, int> freq;
    vector<int> result;
    // loop over each array and insert into hashtable (there are better ways to do this...)
    for (int& num : arr1)
        freq[num]++;
    for (int& num : arr2)
        freq[num]++;
    for (int& num : arr3)
        freq[num]++;
        
    // then find elements in the hashtable that has frequency of 3 and append it to the result
    for (auto& item : freq)
    {
        if (item.second == 3)
            result.push_back(item.first);
    }
    return result;
}

int main() {

    return 0;
}