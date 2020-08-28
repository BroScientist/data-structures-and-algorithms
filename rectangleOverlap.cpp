class Solution {
public:
    bool overlaps(vector<int>& a, vector<int>& b)
    {
        if (a[0] > b[0] && a[0] < b[1])
            return true;
        if (a[1] > b[0] && a[1] < b[1])
            return true;
        if (b[0] > a[0] && b[0] < a[1])
            return true;
        if (b[1] > a[0] && b[1] < a[1])
            return true;
        return false;
    }
    
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        vector<int> x1 = {rec1[0], rec1[2]};
        vector<int> x2 = {rec2[0], rec2[2]};
        
        vector<int> y1 = {rec1[1], rec1[3]};
        vector<int> y2 = {rec2[1], rec2[3]};
        
        if (overlaps(x1, x2) && overlaps(y1, y2))
            return true;
        
        return false;
    }
};