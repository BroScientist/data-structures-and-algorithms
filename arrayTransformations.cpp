#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> transformArray(vector<int>& arr) {
        int changes = 1;
        while (changes != 0)
        {
            changes = 0;
            vector<int> tmp = arr;
            for (int i = 1; i < arr.size() - 1; i++)
            {
                if (tmp[i] < tmp[i-1] && tmp[i] < tmp[i+1])
                {
                    arr[i]++;
                    changes++;
                }
                else if (tmp[i] > tmp[i-1] && tmp[i] > tmp[i+1])
                {
                    arr[i]--;
                    changes++;
                }
            }
        }
        return arr;
        
    }
};

int main() {

    return 0;
}