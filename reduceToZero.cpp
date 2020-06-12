#include <iostream>

using namespace std;

int numberOfSteps(int num)
{
    int steps = 0;
    while (num != 0)
    {
        if (num % 2 == 0) num /= 2;
        else num--;
        steps++;
    }
    return steps;
}
int main() {
    cout << numberOfSteps(14) << endl;
    cout << numberOfSteps(8) << endl;
    cout << numberOfSteps(123) << endl;
    cout << numberOfSteps(1) << endl;
    cout << numberOfSteps(0) << endl;
    return 0;
}