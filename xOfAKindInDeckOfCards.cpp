class Solution {
public:
    int gcd(int x, int y)
    {
        return x == 0 ? y : gcd (y % x, x);
    }
    
    bool hasGroupsSizeX(vector<int>& deck) {
        // count the frequency of each card
        unordered_map<int,int> map;
        for (int& n : deck)
            map[n]++;
        
        // find the greatest common divisor of all card frequencies using the built-in function
        int gcd = -1;
        for (auto& [card, freq] : map)
            gcd = gcd == -1 ? freq : __gcd(gcd, freq);
        
        // return true if gcd is at least 2
        return gcd >= 2;
    }
};