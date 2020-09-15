class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int count = 0;
        unordered_map<int,int> map;
        for (int i = 0; i < points.size(); i++)
        {
            for (int j = 0; j < points.size(); j++)
            {
                int dist = pow(points[j][0] - points[i][0], 2) + pow(points[j][1] - points[i][1], 2);
                count += 2 * map[dist];
                map[dist]++;
            }
            map.clear();
        }
        return count;
    }
};