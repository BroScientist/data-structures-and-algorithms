class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int,int> map;
        for (int& n : arr)
            map[n]++;
        for (int& n : arr)
            if (map.find(2 * n) != map.end())
            {
                if (2 * n != n || map[2 * n] >= 2)
                    return true;
            }
        return false;
    }
};