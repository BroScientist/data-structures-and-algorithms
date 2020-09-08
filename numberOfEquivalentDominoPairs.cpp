class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<vector<int>,int> map;
        int count = 0;
        for (vector<int>& dom : dominoes)
        {
            if (dom[0] > dom[1])
                swap(dom[0], dom[1]);
            if (map.find(dom) != map.end())
                count += map[dom];
            map[dom]++;
        }
        return count;
    }
};