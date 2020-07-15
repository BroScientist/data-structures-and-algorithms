#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double angleClock(int hour, int minutes) {
        if (hour == 12)
            hour = 0;
        double minPos = (double) minutes / 60 * 360;
        double hourPos = (double) (hour + ((double) minutes / 60)) / 12 * 360;
        double angle =  abs(minPos - hourPos);
        return min(angle, abs(360 - angle));
    }
};

int main() {

    return 0;
}