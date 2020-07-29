#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res(num_people);
        int index = 0, curr = 1;
        for (;;)
        {
            if (curr >= candies)
            {
                res[index] += candies;
                break;
            }
            res[index] += curr;
            candies -= curr;
            curr++;
            index++;
            if (index == res.size())
                index = 0;
        }
        return res;
    }
};

int main() {

    return 0;
}