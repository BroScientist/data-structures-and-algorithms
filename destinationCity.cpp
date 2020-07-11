#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        // create a hashtable of all the departure cities
        map<string, int> cityToFreq;
        for (vector<string>& vec : paths)
            cityToFreq[vec[0]]++;
        
        // for every destination city in path, if there is no matching depareture city
        // it means this city is the final destination
        for (vector<string>& vec : paths)
        {
            if (cityToFreq.find(vec[1]) == cityToFreq.end())
                return vec[1];
        }
        return "";
    }
};


int main() {

    return 0;
}