#include <iostream>
#include <vector>

using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int i = 0, j = 0;
    vector<int> res;
    while (i != nums1.size() && j != nums2.size())
    {
        if (nums1[i] == nums2[j])
        {
            res.push_back(nums1[i]);
            i++;
            j++;
            continue;
        }
        if (nums1[i] > nums2[j])
            j++;
        else
            i++;
    }
    return res;
}

int main() {

    return 0;
}