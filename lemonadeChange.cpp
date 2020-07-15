#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    bool lemonadeChange(vector<int>& bills) {
        int fives = 0, tens = 0, twenties = 0;
        
        for (int i = 0; i < bills.size(); i++)
        { 
            if (bills[i] == 5)
                fives++;
            else if (bills[i] == 10)
                tens++;
            else
                twenties++;
            int change = bills[i] - 5;
            while (change != 0)
            {
                if (change >= 20 && twenties != 0)
                {
                    change -= 20;
                    twenties--;
                }
                else if (change >= 10 && tens != 0)
                {
                    change -= 10;
                    tens--;
                }
                else if (change >= 5 && fives != 0)
                {
                    change -= 5;
                    fives--;
                }
                else
                    return false;
            }                
        }
        return true;
    }
};

int main() {

    return 0;
}