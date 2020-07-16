#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        int windowCal = 0, points = 0;
        for (int i = 0; i < k; i++)
            windowCal += calories[i];
        if (windowCal > upper)
            points++;
        else if (windowCal < lower)
            points--;
        // if (k == calories.size())
        //     return points;
        for (int i = k; i < calories.size(); i++)
        {
            windowCal -= calories[i - k];
            windowCal += calories[i];
            if (windowCal > upper)
                points++;
            else if (windowCal < lower)
                points--;
        }
        return points;
    }
};

int main() {

    return 0;
}