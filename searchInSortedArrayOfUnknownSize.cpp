#include <iostream>
#include <vector>

using namespace std;

/**
 * This is the ArrayReader's API interface.
 * You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
public:
    // int low = 0, high = 10000 - 1;
    int res = -1;
    void binarySearch(const ArrayReader& reader, int target, int low, int high)
    {
        if (low <= high)
        {
            int mid = (low + high) / 2;
            if (reader.get(mid) == target)
            {
                res = mid;
                return;
            }
            else if (reader.get(mid) > target)
                binarySearch(reader, target, low, mid - 1);
            else
                binarySearch(reader, target, mid + 1, high);

        }
    }

    int search(const ArrayReader& reader, int target) {
        binarySearch(reader, target, 0, 10000-1);
        return res;
    }
};

