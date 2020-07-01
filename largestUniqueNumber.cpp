#include <iostream>
#include <map>
#include <vector>

using namespace std;

int largestUniqueNumber(vector<int>& A) {
    map<int, int> hashtable;
    for (int& n : A)
        hashtable[n]++;
    int maxItem, maxUnique = 0;
    bool found = false;
    for (auto& item : hashtable)
    {
        if (item.second == 1 && item.first > maxUnique)
        {            
            maxUnique = item.second;
            maxItem = item.first;
            found = true;
        }
    }
    if (found)
        return maxItem;
    return -1;
            
}
int main() {
    vector<int> vec1{5,7,3,9,4,9,8,3,1};
    cout << largestUniqueNumber(vec1) << endl;
    vector<int> vec2{9, 9, 8, 8};
    cout << largestUniqueNumber(vec2) << endl;
    return 0;
}