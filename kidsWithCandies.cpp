#include <iostream>
#include <vector>

using namespace std;
vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies)
{
    vector<bool> results;
    int max = *max_element(candies.begin(), candies.end());
    for (int& kid : candies)
    {
        if (kid + extraCandies >= max) results.push_back(true);
        else results.push_back(false);
    }
    for (bool r : results) cout << r << endl;
    return results;
}

int main() {
    vector<int> candies;
    candies = {12,1,12};
    kidsWithCandies(candies, 10);
    return 0;
}